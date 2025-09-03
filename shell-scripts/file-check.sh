#!/bin/bash
# file-check.sh
# Usage: ./file-check.sh <path>  (or run and it will prompt you)

PATH_ARG="$1"

if [ -z "$PATH_ARG" ]; then
  read -p "Enter a file path to check: " PATH_ARG
fi

echo "\$ Checking: $PATH_ARG"

if [ -e "$PATH_ARG" ]; then
  echo "Exists."
  if [ -d "$PATH_ARG" ]; then
    echo "Type: directory"
    echo "--- ls -ld ---"
    ls -ld "$PATH_ARG"
  else
    echo "Type: file"
    echo "--- ls -l ---"
    ls -l "$PATH_ARG"
    echo "--- first 5 lines (if text) ---"
    head -n 5 "$PATH_ARG" 2>/dev/null
  fi
else
  echo "Not found."
fi
