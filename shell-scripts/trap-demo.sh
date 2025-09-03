#!/bin/bash
# trap-demo.sh

set -e
trap 'echo "Error!"' ERR

echo "About to run a command that fails..."
false

echo "You won't see this line because set -e stops the script."
