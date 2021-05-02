#!/usr/bin/awk -f
NR>1{a+=$2-$1+1}END{print a}
