#!/bin/bash
# args-demo.sh

ARGS=("$@")
echo "First arg: ${ARGS[0]}"

for arg in "$@"; do
  echo "$arg"
done
