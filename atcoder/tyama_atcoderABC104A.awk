#!/usr/bin/awk -f
$0=$1<1200?"ABC":$1<2800?"ARC":"AGC"
