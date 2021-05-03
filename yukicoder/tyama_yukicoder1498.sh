#!/bin/sh
awk '$0=$1*$1+1'|factor|sed 1d\;s/.*://
