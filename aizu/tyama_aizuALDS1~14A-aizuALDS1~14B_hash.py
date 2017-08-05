#!/usr/bin/python
B=999999937
P=1000000007

def gen_hash(s,hash):
	c=0
	for i in range(len(s)):
		c=(c*B+s[i])%P
		hash[i]=c

import sys
s=[ord(e) for e in sys.stdin.readline().strip()]
ls=len(s)
v=[0]*ls
hsh=[0]*10001
gen_hash(s,v)
q=[ord(e) for e in sys.stdin.readline().strip()]
lq=len(q)
gen_hash(q,hsh)
hash=hsh[lq-1]
Brev=pow(B,lq,P)
r=[]
for i in range(lq-1,ls):
	if v[i]==((v[i-lq] if i>=lq else 0)*Brev+hash)%P:
		r.append(i-lq+1)
for e in r:print(e)
