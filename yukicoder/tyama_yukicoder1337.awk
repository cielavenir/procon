#!/usr/bin/awk -f
$0=($1+$2+$3)%3?"No":"Yes"
