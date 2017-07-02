#!/usr/bin/env python
#http://nabetani.sakura.ne.jp/hena/orde15nohil/
#http://qiita.com/Nabetani/items/705fa83cfbf20377b92f

import sys
if sys.version_info[0]>=3: raw_input=input

def num2place(n):
	x=y=0
	z=1
	while n>0:
		if n%3==1:
			x+=z
		elif n%3==2:
			y+=z
		n//=3
		z*=2
	return (x,y)

def place2num(x,y):
	if x<0 or y<0 or x&y>0: return None
	n=0
	z=1
	while x>0 or y>0:
		if x%2>0:
			n+=z
		elif y%2>0:
			n+=2*z
		x//=2
		y//=2
		z*=3
	return n

try:
	while True:
		x,y=num2place(int(raw_input()))
		a=[place2num(x+dx,y+dy) for (dx,dy) in [(0,-1),(-1,0),(1,0),(0,1)]]
		print(','.join(str(e) for e in a if e is not None))
		sys.stdout.flush()
except EOFError:
	pass
