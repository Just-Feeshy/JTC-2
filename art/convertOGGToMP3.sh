#!/usr/bin/env sh

set -eu

# Match upstream Funkin's web-audio conversion step.
# Creates sibling .mp3 files next to each .ogg without overwriting existing files.
find "../assets/" "../mod_assets/" -name "*.ogg" -exec sh -c '
  for file do
    ffmpeg -n -i "$file" "${file%.*}.mp3"
  done
' sh {} +
