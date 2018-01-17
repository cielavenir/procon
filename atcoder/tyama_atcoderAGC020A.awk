#!/usr/bin/awk -f
$0=($3-$2)%2?"Borys":"Alice"
