#!/usr/bin/python
import sys
def checkio(r):
	flg=0
	xxx=''
	j=0
	while r>0:
		xxx+=chr(r%26+65-1-flg)
		flg=0
		if xxx[j]=='@':
			xxx=xxx[:j]+'Z'
			flg=1
		if xxx[j]=='?':
			xxx=xxx[:j]+'Y'
			flg=1
		j+=1
		r//=26
	if flg>0:
		j-=1
		xxx=xxx[:j]
	return xxx[::-1]

def checkio2(s):
	r=0
	for c in s:
		c=c.upper()
		r*=26
		r+=ord(c)-65+1
	return r

sys.stdin.readline()
print(' '.join(checkio(int(e)) if e.isdigit() else str(checkio2(e)) for e in sys.stdin.readline().split()))
