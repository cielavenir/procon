#!/usr/bin/env io
f := File standardInput
n := doString(f readLine)
a := 1
b := 1
for(i,2,n,
	c:=a+b
	a:=b
	b:=c
)
b println