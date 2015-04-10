#!/bin/bash
i=0
while read s;do
	a[$i]=$s
	i=$((i+1))
done
echo ${a[@]} ${a[@]} ${a[@]}