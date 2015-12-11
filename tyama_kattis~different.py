#!/usr/bin/python
try:
	while True:
		a,b=[int(e) for e in raw_input().split()]
		print(abs(a-b))
except EOFError:
	pass