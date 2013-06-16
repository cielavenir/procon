#!/usr/bin/python
#May 20: Python3 compat
import sys
import random
a=[]
for line in sys.stdin:
	a+=[line.rstrip()]
while True:
	b=random.sample(a,3)
	f=False
	for e in b:
		try:
			e.index('Chicken')
			#if the menu includes Chicken, usually it is ordinary one.
			f=True
		except ValueError:
			pass
	if f:
		for e in b: print(e)
		break