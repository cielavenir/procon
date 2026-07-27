#!/usr/bin/awk -f
BEGIN{OFMT="%.9f"}$0=-8.245+6.807*$1+14.146*$2*atan2(0,-1)
