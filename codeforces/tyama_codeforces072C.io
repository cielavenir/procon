#!/usr/bin/env io
f := File standardInput
n := doString(f readLine)
r := 0
for(i,1,n,
	if(n%i==0,
		if(i%2==0,r:=r+1,r:=r-1)
	)
)
if(r==0,"yes","no") println