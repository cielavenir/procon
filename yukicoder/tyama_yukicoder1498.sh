#!/bin/sh
awk '{printf("%.0f\n",$1*$1+1)}'|factor|sed 1d\;s/.*://
