#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def fib():
	a=0
	b=1
	yield a
	while True:
		yield b
		a,b=b,a+b

print([e[0]**3 for e in zip(fib(),range(int(raw_input())))])