#!/usr/bin/awk -f
$0=($1-$2)^2<2?"Brown":"Alice"
