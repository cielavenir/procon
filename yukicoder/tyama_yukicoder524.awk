#!/usr/bin/awk -f
$0=$1%4<3?"O":"X"
