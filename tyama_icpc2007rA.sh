#!/bin/bash
set -eu
while :; do
	read n k m
	if [ $n -eq 0 ]; then break; fi
	r=0
	i=1
	for i in `seq 1 $((n-1))`; do
	#while [ $i -lt $n ]; do
		r=$(((r+k)%i))
		#i=$((i+1))
	done
	echo $(((r+m)%n+1))
done