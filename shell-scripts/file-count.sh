#!/bin/bash
# file-count.sh

trap 'echo "Error!"; exit 1' ERR

DIR="${1:-.}"  

if [ ! -d "$DIR" ]; then
  echo "Directory not found: $DIR"
  exit 1
fi

LOG="file-count.log"
{
  echo "\$ ./file-count.sh $DIR"
  echo "Directory: $DIR"
  date


  TOTAL=$(find "$DIR" -type f 2>/dev/null | wc -l)
  echo "TOTAL files: $TOTAL"

  for ext in txt sh md py jpg png pdf; do
    count=$(find "$DIR" -type f -name "*.${ext}" 2>/dev/null | wc -l)
    echo ".${ext}: $count"
  done

  echo "----------"
} | tee -a "$LOG"
