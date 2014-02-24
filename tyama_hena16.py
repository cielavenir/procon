#!/usr/bin/env python
#http://qiita.com/Nabetani/items/6a9f5593d0f3d7e0568c
#http://nabetani.sakura.ne.jp/hena/ord16boseg/
import sys
if sys.version_info[0]>=3: raw_input=input

def solve(s):
	r=[0]*7
	a=[list(format(int(s[i:i+2],8),'06b')) for i in range(0,len(s),2)]
	for e in [a,list(zip(*a))]:
		for y in range(5):
			z=['1' if e[y][x]!=e[y+1][x] else ' ' for x in range(6)]
			for f in ''.join(z).split():
				r[len(f)]+=1
	print(','.join(str(e) for e in r[1:]))
	sys.stdout.flush()

try:
	while True:
		s=raw_input()
		solve(s)
except EOFError:
	pass