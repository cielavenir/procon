#!/usr/bin/env Rscript
x=scan("stdin")
x=x[2:length(x)]
i=0
repeat{
	if(i==length(x))break
	y=x[i+1]-1
	m=x[i+2]-1
	d=x[i+3]
	cat(196471-y*195-y%/%3*5-m*20+ifelse(y%%3!=2,m%/%2,0)-d)
	cat("\n")
	i=i+3
}