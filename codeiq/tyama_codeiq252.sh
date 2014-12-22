#!/bin/sh
#sh 252.sh <names.dmp
#1.
grep -i virus | sort -d -f -t "|" -k 2
# | less -S
#2.
#grep -i virus | wc -l