#!/bin/bash
# Only works for mac

set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
APP_BUNDLE="$ROOT_DIR/export/debug/macos/bin/Joul The Cool.app"
TARGET_MOD_ASSETS="$APP_BUNDLE/Contents/Resources/mod_assets"

rm -rf "$TARGET_MOD_ASSETS"
cp -R "$ROOT_DIR/mod_assets" "$TARGET_MOD_ASSETS"
open "$APP_BUNDLE"
