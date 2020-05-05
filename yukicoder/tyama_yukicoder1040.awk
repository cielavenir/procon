#!/usr/bin/awk -f
$0=$1%180-90?"No":"Yes"
