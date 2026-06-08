#!/usr/bin/env python3

from __future__ import annotations

import argparse
import shutil
import sys
from pathlib import Path


def find_latest_path(paths: list[Path]) -> Path | None:
    candidates = [path for path in paths if path.exists()]
    if not candidates:
        return None

    return sorted(candidates, key=lambda path: path.stat().st_mtime, reverse=True)[0]


def find_target_mod_assets(root_dir: Path) -> Path | None:
    mac_bin_dir = root_dir / "export" / "debug" / "macos" / "bin"
    if mac_bin_dir.is_dir():
        app_bundle = find_latest_path([path for path in mac_bin_dir.glob("*.app") if path.is_dir()])
        if app_bundle is not None:
            return app_bundle / "Contents" / "Resources" / "mod_assets"

    windows_bin_dir = root_dir / "export" / "debug" / "windows" / "bin"
    if windows_bin_dir.is_dir():
        exe = find_latest_path([path for path in windows_bin_dir.glob("*.exe") if path.is_file()])
        if exe is not None:
            return exe.parent / "mod_assets"

    linux_bin_dir = root_dir / "export" / "debug" / "linux" / "bin"
    if linux_bin_dir.is_dir():
        return linux_bin_dir / "mod_assets"

    return None


def resolve_target_mod_assets(target: Path) -> Path:
    if target.suffix.lower() == ".app" and target.is_dir():
        return target / "Contents" / "Resources" / "mod_assets"

    if target.suffix.lower() == ".exe":
        return target.parent / "mod_assets"

    if target.is_dir():
        if target.name == "mod_assets":
            return target

        contents_resources = target / "Contents" / "Resources"
        if contents_resources.is_dir():
            return contents_resources / "mod_assets"

        return target / "mod_assets"

    return target


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Replace mod_assets in an export/debug build with the repo's mod_assets directory.",
    )
    parser.add_argument(
        "target",
        nargs="?",
        help="Path to the app bundle, exe, export root, or mod_assets directory. Defaults to the newest debug build.",
    )
    parser.add_argument(
        "--source",
        default=None,
        help="Path to the source mod_assets directory. Defaults to mod_assets in this repo.",
    )
    args = parser.parse_args()

    root_dir = Path(__file__).resolve().parent
    source = Path(args.source).expanduser() if args.source else root_dir / "mod_assets"

    if not source.is_dir():
        print(f"Source mod_assets directory not found: {source}", file=sys.stderr)
        return 1

    if args.target:
        target_mod_assets = resolve_target_mod_assets(Path(args.target).expanduser())
    else:
        target_mod_assets = find_target_mod_assets(root_dir)

    if target_mod_assets is None:
        print(
            "No export target found. Pass one explicitly or build a debug target first.",
            file=sys.stderr,
        )
        return 1

    if not target_mod_assets.parent.is_dir():
        print(f"Export target parent not found: {target_mod_assets.parent}", file=sys.stderr)
        return 1

    if target_mod_assets.exists():
        shutil.rmtree(target_mod_assets)
    shutil.copytree(source, target_mod_assets)

    print(f"Replaced mod_assets at: {target_mod_assets}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
