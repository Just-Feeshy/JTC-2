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
    binary = app_bundle / "Contents" / "MacOS" / "Joul The Cool"

    if target_mod_assets.exists():
        shutil.rmtree(target_mod_assets)
    shutil.copytree(source_mod_assets, target_mod_assets)

    # Launch the binary directly (instead of `open Joul.app`) so stdout/stderr
    # stay attached to this terminal — needed for capturing crash traces.
    # The crash handler in Preloader.hx also writes ./crash-reports/<modName>_<ts>.txt
    # relative to the working directory we set below.
    result = subprocess.run(
        [str(binary)],
        cwd=str(app_bundle / "Contents" / "Resources"),
    )
    return result.returncode


if __name__ == "__main__":
    raise SystemExit(main())
