#!/usr/bin/env python
#http://nabetani.sakura.ne.jp/hena/orde24tancho/
#https://qiita.com/Nabetani/items/928d6a94d83c21ef64d7
from __future__ import print_function,division
import string
o = string.digits+string.ascii_letters

def comb(n,k):
	r=1
	for i in range(k):
		r=r*(n-i)//(i+1)
	return r

if __name__=='__main__':
	import sys
	if sys.version_info[0]>=3: raw_input=input
	try:
		while True:
			b,n=[int(e)-1 for e in raw_input().rstrip().split(',')]
			topdigit=1
			while 1:
				x=comb(b,topdigit)
				if b<topdigit or x>n: break
				n-=x
				topdigit+=1
			if b<topdigit:
				print('-')
				sys.stdout.flush()
				continue
			topdigit-=1
			curnumber=0
			for d in range(topdigit,-1,-1):
				curnumber+=1
				while 1:
					x=comb(b-curnumber,d)
					if x>n: break
					n-=x
					curnumber+=1
				print(o[curnumber],end='')
			print()
			sys.stdout.flush()
	except EOFError:
		pass
