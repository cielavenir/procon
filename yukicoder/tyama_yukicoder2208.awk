#!/usr/bin/awk -f
NR>1{print ($3<0?$1:$2)*$3+$4a}