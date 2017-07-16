#!/usr/bin/awk -f
$0=($1%3&&$2%3&&($1+$2)%3?"Imp":"P")"ossible"
