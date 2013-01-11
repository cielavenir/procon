#!/usr/bin/awk -f
{
	Y[FNR]=$1
	M[FNR]=$2
	D[FNR]=$3
}
END{for(n=2;n<=Y[1]+1;n++){
	y=Y[n]-1
	m=M[n]-1
	print 196471-y*195-int(y/3)*5-m*20+(y%3!=2?int(m/2):0)-D[n]
}}