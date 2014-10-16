#!/bin/bash
set -eu
read n
i=0
while [ $i -ne $n ]; do
	read y m d
	y=$((y - 1))
	m=$((m - 1))
	r=0
	if [ $((y % 3)) -ne 2 ]; then r=$((m / 2)); fi
	echo $((196471 - y * 195 - y / 3 * 5 - m * 20 + r - d))
	i=$((i + 1))
done