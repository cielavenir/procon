#!/usr/bin/awk -f
$0=$1>$3||$3>$1+$2?"NO":"YES"
