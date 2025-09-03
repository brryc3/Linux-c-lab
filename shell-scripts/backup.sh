#!/bin/bash
# backup.sh
# Tar up all .txt files in the current directory into backup.tar.gz

tar -czf backup.tar.gz *.txt
echo "Created backup.tar.gz (all *.txt files)"
