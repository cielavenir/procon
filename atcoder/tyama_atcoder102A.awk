#!/usr/bin/awk -f
$0=int($1/2)*(int($1/2)+$1%2)
