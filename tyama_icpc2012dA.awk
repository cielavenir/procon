#!/usr/bin/awk -f
NF==3 {
	y=$1-1
	m=$2-1
	print 196471-y*195-int(y/3)*5-m*20+(y%3!=2?int(m/2):0)-$3
}