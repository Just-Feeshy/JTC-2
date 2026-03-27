#!/usr/bin/env python3

from __future__ import annotations

import subprocess
from pathlib import Path


def iter_ogg_files(root_dir: Path):
    for base_name in ("assets", "mod_assets"):
        base_dir = root_dir / base_name
        if not base_dir.is_dir():
            continue
        yield from base_dir.rglob("*.ogg")


def main() -> int:
    root_dir = Path(__file__).resolve().parent.parent

    for source_file in iter_ogg_files(root_dir):
        target_file = source_file.with_suffix(".mp3")
        subprocess.run(
            ["ffmpeg", "-n", "-i", str(source_file), str(target_file)],
            check=True,
        )

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
