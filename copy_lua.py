#!/usr/bin/env python3

from __future__ import annotations

import shutil
import sys
from pathlib import Path


def main() -> int:
    root_dir = Path(__file__).resolve().parent
    source_scripts = root_dir / "mod_assets" / "scripts"

    if not source_scripts.is_dir():
        print(f"Source scripts directory not found: {source_scripts}", file=sys.stderr)
        return 1

    if sys.platform == "win32":
        target_mod_assets = root_dir / "export" / "debug" / "windows" / "bin" / "mod_assets"
    else:
        app_bundle = root_dir / "export" / "debug" / "macos" / "bin" / "Joul The Cool.app"
        target_mod_assets = app_bundle / "Contents" / "Resources" / "mod_assets"

    if not target_mod_assets.parent.is_dir():
        print(f"Debug build not found: {target_mod_assets.parent}", file=sys.stderr)
        return 1

    target_scripts = target_mod_assets / "scripts"
    target_mod_assets.mkdir(parents=True, exist_ok=True)
    if target_scripts.exists():
        shutil.rmtree(target_scripts)
    shutil.copytree(source_scripts, target_scripts)

    print(f"Copied Lua scripts to: {target_scripts}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
