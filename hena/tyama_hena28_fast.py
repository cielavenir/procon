#!/usr/bin/env python
#http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
#http://nabetani.sakura.ne.jp/hena/ord28spirwa/

dir='ESWN'
if __name__=='__main__':
	import sys,itertools
	if sys.version_info[0]>=3: raw_input=input
	try:
		while True:
			line=raw_input().rstrip().split(':')
			n,e,s,w=[int(e) for e in line[0].split(',')]
			l=[e,s,w,n]
			days=int(line[1])+1
			for i in itertools.count(0):
				for j,e in enumerate([l[i%4]+(i%4==0),(i//4+1)*2,l[i%4]-(i%4==3)]):
					if days-e<0:
						print(dir[(i+j)%4])
						break
					days-=e
				else:
					continue
				break
			sys.stdout.flush()
	except EOFError:
		pass