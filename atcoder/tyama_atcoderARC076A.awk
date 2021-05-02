#!/usr/bin/awk -f
$0=($3-=$2)>$1?"dangerous":$3>0?"safe":"delicious"
