#!/usr/bin/awk -f
{x[FNR]=$1}
END{for(n=1;;){
	m=x[n]
	if(m==0)break
	s=0
	ma=0
	mi=1000
	for(i=n+1;i<=n+m;i++){
		s=s+x[i]
		if(ma<x[i])ma=x[i]
		if(mi>x[i])mi=x[i]
	}
	print int((s-ma-mi)/(m-2))
	n=n+m+1
}}