#!/usr/bin/env python
#http://nabetani.sakura.ne.jp/hena/orde16nontri/
#http://qiita.com/Nabetani/items/3525da55601bdf55316e

import sys
if sys.version_info[0]>=3: raw_input=input

W=3
q=lambda n:''.join('1' if i%W==W-1 else '0' for i in range(n))

try:
	while True:
		s='0'+bin(int(raw_input())+1)[2:]
		try:
			idx=s.index('0'+'1'*W)
			s=s[0:idx]+'1'+q(len(s)-(idx+1))
		except ValueError:
			pass
		try:
			idx=s.index('0'*W)
			s=s[0:idx+W-1]+'1'+q(len(s)-(idx+W))
		except ValueError:
			pass
		print(int(s,2))
		sys.stdout.flush()
except EOFError:
	pass
