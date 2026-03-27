#!/usr/bin/env python3

from __future__ import annotations

import shutil
import subprocess
from pathlib import Path


def main() -> int:
    root_dir = Path(__file__).resolve().parent
    app_bundle = root_dir / "export" / "debug" / "macos" / "bin" / "Joul The Cool.app"
    target_mod_assets = app_bundle / "Contents" / "Resources" / "mod_assets"
    source_mod_assets = root_dir / "mod_assets"

    if target_mod_assets.exists():
        shutil.rmtree(target_mod_assets)
    shutil.copytree(source_mod_assets, target_mod_assets)
    subprocess.run(["open", str(app_bundle)], check=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
