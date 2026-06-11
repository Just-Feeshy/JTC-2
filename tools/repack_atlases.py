#!/usr/bin/env python3
"""
Repack 8192x8192 Sparrow texture atlases into 4096x4096 sheets.

- Deduplicates frames that share identical source rects (saves repacking cost).
- Shelf-packs unique rects by height-descending for dense coverage.
- frameX/frameY/frameWidth/frameHeight are preserved verbatim (game positioning unchanged).
- Backs up original PNG+XML before writing.
- Updates character JSON "file" fields when an atlas splits into multiple sheets.
"""

import os, json, shutil
import xml.etree.ElementTree as ET
from PIL import Image

IMAGE_DIR  = "mod_assets/images"
CHAR_DIR   = "mod_assets/characters"
BACKUP_DIR = os.path.join(IMAGE_DIR, "_backup")
TARGET     = 4096
PAD        = 2   # gap between frames to prevent bleed

ATLASES = [
    "skater_assets",
    "skater extra notes",
    "daddycar",
    "flying notes BF SINGS",
    "flying notes GF SINGS",
    "skating and flying DEATH",
    "skating and flying DEATHDEMON",
    "DD_assets",
]

# Character JSONs whose "file" field may need updating
CHAR_JSONS = [
    "frostbeat-second.json",
    "dad-car.json",
    "flying BF sings.json",
    "flying BF sings gf.json",
]


# ---------------------------------------------------------------------------
# Bin-packing: shelf algorithm
# ---------------------------------------------------------------------------

def shelf_pack(items, sheet_size, pad):
    """
    Pack (key, w, h) tuples into sheet_size × sheet_size bins.
    Returns list-of-sheets; each sheet is [(key, x, y, w, h), ...].
    """
    sheets, cur = [], []
    shelf_x = shelf_y = pad
    shelf_h = 0

    def flush():
        nonlocal cur, shelf_x, shelf_y, shelf_h
        if cur:
            sheets.append(cur)
        cur = []
        shelf_x = shelf_y = pad
        shelf_h = 0

    for key, w, h in items:
        if w > sheet_size - pad * 2 or h > sheet_size - pad * 2:
            print(f"    WARN: frame too large for {sheet_size}px sheet ({w}x{h}) — keeping as-is")
            continue

        if shelf_x + w + pad > sheet_size:      # doesn't fit horizontally
            shelf_y += shelf_h + pad
            shelf_x = pad
            shelf_h = 0

        if shelf_y + h + pad > sheet_size:      # doesn't fit vertically
            flush()

        cur.append((key, shelf_x, shelf_y, w, h))
        shelf_x += w + pad
        shelf_h = max(shelf_h, h)

    flush()
    return sheets


# ---------------------------------------------------------------------------
# Per-atlas work
# ---------------------------------------------------------------------------

def repack(base):
    xml_path = os.path.join(IMAGE_DIR, base + ".xml")
    png_path = os.path.join(IMAGE_DIR, base + ".png")

    if not (os.path.exists(xml_path) and os.path.exists(png_path)):
        print(f"  skip {base!r}: files not found")
        return [base]

    # ---- parse ----
    tree   = ET.parse(xml_path)
    root   = tree.getroot()
    frames = root.findall("SubTexture")

    # Map (x,y,w,h) → list of matching SubTexture elements
    uniq: dict = {}
    for f in frames:
        k = (int(f.get("x")), int(f.get("y")),
             int(f.get("width")), int(f.get("height")))
        uniq.setdefault(k, []).append(f)

    total_unique = len(uniq)
    print(f"\n  {base}: {len(frames)} frames → {total_unique} unique regions")

    # ---- pack ----
    items = sorted(
        [(k, k[2], k[3]) for k in uniq],
        key=lambda t: (-t[2], -t[1])   # height desc, then width desc
    )
    sheets = shelf_pack(items, TARGET, PAD)
    print(f"  → {len(sheets)} sheet(s) of {TARGET}×{TARGET}")

    # coord_map: old_key → (sheet_idx, new_x, new_y)
    coord_map = {}
    for si, sheet in enumerate(sheets):
        for key, nx, ny, w, h in sheet:
            coord_map[key] = (si, nx, ny)

    # ---- composite images ----
    src = Image.open(png_path).convert("RGBA")
    canvases = [Image.new("RGBA", (TARGET, TARGET), (0, 0, 0, 0))
                for _ in sheets]

    for key, elem_list in uniq.items():
        if key not in coord_map:
            continue
        ox, oy, ow, oh = key
        si, nx, ny = coord_map[key]
        canvases[si].paste(src.crop((ox, oy, ox + ow, oy + oh)), (nx, ny))

    src.close()

    # ---- backup originals ----
    os.makedirs(BACKUP_DIR, exist_ok=True)
    for suffix in (".png", ".xml"):
        src_file = os.path.join(IMAGE_DIR, base + suffix)
        dst_file = os.path.join(BACKUP_DIR, base + suffix)
        if not os.path.exists(dst_file) and os.path.exists(src_file):
            shutil.copy2(src_file, dst_file)

    # ---- write sheets ----
    out_bases = []
    for si, canvas in enumerate(canvases):
        out_base = base if si == 0 else f"{base}_p{si}"
        out_bases.append(out_base)

        out_png = os.path.join(IMAGE_DIR, out_base + ".png")
        out_xml = os.path.join(IMAGE_DIR, out_base + ".xml")

        canvas.save(out_png, "PNG", optimize=True)

        orig_mb = os.path.getsize(png_path) // (1024 * 1024)
        new_mb  = os.path.getsize(out_png)  // (1024 * 1024)
        vram_mb = (TARGET * TARGET * 4) // (1024 * 1024)   # uncompressed RGBA
        if si == 0:
            print(f"    sheet 0: {out_base}.png  "
                  f"file {orig_mb}MB→{new_mb}MB  |  VRAM {256}→{vram_mb} MB")
        else:
            print(f"    sheet {si}: {out_base}.png  "
                  f"file {new_mb}MB  |  VRAM +{vram_mb} MB")

        # Build XML for this sheet only
        new_root = ET.Element("TextureAtlas")
        new_root.set("imagePath", out_base + ".png")

        # Iterate in original document order so frame indices stay stable
        for f in frames:
            k = (int(f.get("x")), int(f.get("y")),
                 int(f.get("width")), int(f.get("height")))
            if k not in coord_map:
                continue
            s_idx, nx, ny = coord_map[k]
            if s_idx != si:
                continue

            sub = ET.SubElement(new_root, "SubTexture")
            sub.set("name",   f.get("name"))
            sub.set("x",      str(nx))
            sub.set("y",      str(ny))
            sub.set("width",  f.get("width"))
            sub.set("height", f.get("height"))
            # Preserve all positioning metadata unchanged
            for attr in ("frameX", "frameY", "frameWidth", "frameHeight",
                         "rotated", "flipX", "flipY"):
                v = f.get(attr)
                if v is not None:
                    sub.set(attr, v)

        with open(out_xml, "wb") as fp:
            fp.write(b'<?xml version="1.0" encoding="utf-8"?>\n')
            fp.write(ET.tostring(new_root, encoding="unicode").encode("utf-8"))

    return out_bases


# ---------------------------------------------------------------------------
# Update character JSONs
# ---------------------------------------------------------------------------

def update_char_jsons(atlas_map: dict):
    """atlas_map: { old_base: [new_base_0, new_base_1, ...] }"""
    for fname in CHAR_JSONS:
        path = os.path.join(CHAR_DIR, fname)
        if not os.path.exists(path):
            continue

        with open(path, encoding="utf-8") as fp:
            data = json.load(fp)

        file_field = data.get("file", "")
        if not file_field:
            continue

        parts = [p.strip() for p in file_field.split(",")]
        new_parts = []
        changed = False

        for part in parts:
            base = part[:-4] if part.endswith(".xml") else part
            if base in atlas_map:
                new_parts += [b + ".xml" for b in atlas_map[base]]
                changed = True
            else:
                new_parts.append(part)

        if changed:
            # Back up JSON
            bk = os.path.join(BACKUP_DIR, fname)
            if not os.path.exists(bk):
                shutil.copy2(path, bk)

            data["file"] = ", ".join(new_parts)
            with open(path, "w", encoding="utf-8") as fp:
                json.dump(data, fp, indent="\t", ensure_ascii=False)
            print(f"  {fname}: file → {data['file']}")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

    atlas_map = {}
    vram_before = vram_after = 0

    for base in ATLASES:
        out_bases = repack(base)
        atlas_map[base] = out_bases
        vram_before += 256
        vram_after  += len(out_bases) * 64

    print("\n  Updating character JSONs...")
    update_char_jsons(atlas_map)

    print(f"\n  VRAM estimate:  {vram_before} MB  →  {vram_after} MB")
    print(f"  Reduction:      ~{vram_before - vram_after} MB  "
          f"({(vram_before - vram_after) / vram_before * 100:.0f}%)")
    print("\n  Originals backed up to mod_assets/images/_backup/")
    print("  Done.")


if __name__ == "__main__":
    main()
