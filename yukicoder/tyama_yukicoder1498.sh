#!/bin/sh
awk \$0=\$1^2+1|factor|sed 1d\;s/.*://
