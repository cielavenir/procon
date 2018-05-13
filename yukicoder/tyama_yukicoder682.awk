#!/usr/bin/awk -f
$0=int(($2-=$1)/3)+1-$2%3%2a
