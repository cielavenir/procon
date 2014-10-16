#!/usr/bin/env Rscript
x=scan("stdin")
j=0
repeat{
	n=x[j+1]
	k=x[j+2]
	m=x[j+3]
	if(n==0)break
	r=0
	for(i in 1:(n-1))r=(r+k)%%i
	cat((r+m)%%n+1)
	cat("\n")
	j=j+3
}