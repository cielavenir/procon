#!/usr/bin/awk -f
$0=($1+=$2)>9?"error":$1
