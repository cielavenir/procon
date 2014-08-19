#!/usr/bin/env python
#http://qiita.com/Nabetani/items/6a9f5593d0f3d7e0568c
#http://nabetani.sakura.ne.jp/hena/ord16boseg/
import sys
if sys.version_info[0]>=3:
	from functools import reduce
	raw_input=input

def solve(s):
	a=[int(s[i:i+2],8) for i in range(0,len(s),2)]
	r=[0]*(len(a)+1)
	for e in (a,[reduce(lambda s,f: s+(((a[f]>>e)&1)<<f),range(len(a)),0) for e in range(len(a))]):
		for y in range(len(a)-1):
			for f in format(e[y]^e[y+1],'b').split('0'): r[len(f)]+=1
	print(','.join(str(e) for e in r[1:]))
	sys.stdout.flush()

try:
	while True:
		s=raw_input()
		solve(s)
except EOFError:
	pass