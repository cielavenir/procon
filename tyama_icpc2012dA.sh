#!/bin/sh
read n
i=0
while [ $i -ne $n ]; do
	read y m d
	y=`expr $y - 1`
	m=`expr $m - 1`
	r=0
	if [ `expr $y % 3` -ne 2 ]; then r=`expr $m / 2`; fi
	expr 196471 - $y \* 195 - $y / 3 \* 5 - $m \* 20 + $r - $d
	i=`expr $i + 1`
done