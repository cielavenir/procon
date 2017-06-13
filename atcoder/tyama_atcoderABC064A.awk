#!/usr/bin/awk -f
$0=($2*2+$3)%4?"NO":"YES"
