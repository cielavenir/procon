#!/usr/bin/env python
#http://qiita.com/Nabetani/items/cba03c96d1ea55f6e861
#http://nabetani.sakura.ne.jp/hena/ord15elebubo/
import sys
if sys.version_info[0]>=3: raw_input=input

def solve(s):
	v=[int(x,16) for x in s.split('/')]
	a=[ [((v[i]>>(31-j))&1)>0 for j in range(32)]+[False]*2 for i in range(2) ]
	s=''
	i=0
	while i<32:
		if not a[0][i] and not a[1][i]:
			i+=1
		elif a[0][i] and a[1][i]:
			if a[0][i+1]:
				if a[0][i+2]:
					s+='N'
					i+=3
				else:
					s+='R'
					i+=2
			elif a[1][i+1]:
				if a[1][i+2]:
					s+='U'
					i+=3
				else:
					s+='L'
					i+=2
		elif a[0][i]:
			if a[0][i+2]:
				s+='T'
				i+=3
			else:
				s+='Z'
				i+=3
		else:
			if a[0][i+2]:
				s+='S'
				i+=3
			else:
				s+='J'
				i+=2
	print(s)
	sys.stdout.flush()

try:
	while True:
		s=raw_input()
		solve(s)
except EOFError:
	pass