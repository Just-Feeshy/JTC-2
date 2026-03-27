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


def find_target_root(root_dir: Path) -> Path | None:
    mac_bin_dir = root_dir / "export" / "debug" / "macos" / "bin"
    if mac_bin_dir.is_dir():
        app_bundle = find_latest_path([path for path in mac_bin_dir.glob("*.app") if path.is_dir()])
        if app_bundle is not None:
            return app_bundle / "Contents" / "Resources"

    windows_bin_dir = root_dir / "export" / "debug" / "windows" / "bin"
    if windows_bin_dir.is_dir():
        exe = find_latest_path([path for path in windows_bin_dir.glob("*.exe") if path.is_file()])
        if exe is not None:
            return exe.parent

    return None


def resolve_target_root(app_bundle: Path) -> Path:
    if app_bundle.suffix.lower() == ".app" and app_bundle.is_dir():
        return app_bundle / "Contents" / "Resources"

    if app_bundle.suffix.lower() == ".exe":
        return app_bundle.parent

    if app_bundle.is_dir():
        contents_resources = app_bundle / "Contents" / "Resources"
        if contents_resources.is_dir():
            return contents_resources

        return app_bundle

    return app_bundle


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Copy mod_assets Lua scripts into a game export root."
    )
    parser.add_argument(
        "target",
        nargs="?",
        help="Path to the app bundle, exe, or export root. Defaults to the newest macOS .app or Windows .exe under export/debug.",
    )
    parser.add_argument(
        "--source-scripts",
        default=None,
        help="Path to the source scripts directory. Defaults to mod_assets/scripts in this repo.",
    )
    args = parser.parse_args()

    root_dir = Path(__file__).resolve().parent
    source_scripts = Path(args.source_scripts) if args.source_scripts else root_dir / "mod_assets" / "scripts"

    if args.target:
        target_root = resolve_target_root(Path(args.target).expanduser())
    else:
        target_root = find_target_root(root_dir)

    if target_root is None:
        print("No export target found. Pass one explicitly or build the macOS/Windows target first.", file=sys.stderr)
        return 1

    target_mod_assets = target_root / "mod_assets"
    target_scripts = target_mod_assets / "scripts"

    if not target_root.is_dir():
        print(f"Export target root not found: {target_root}", file=sys.stderr)
        return 1

    if not source_scripts.is_dir():
        print(f"Source scripts directory not found: {source_scripts}", file=sys.stderr)
        return 1

    target_mod_assets.mkdir(parents=True, exist_ok=True)
    if target_scripts.exists():
        shutil.rmtree(target_scripts)
    shutil.copytree(source_scripts, target_scripts)

    print(f"Copied Lua scripts to: {target_scripts}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
