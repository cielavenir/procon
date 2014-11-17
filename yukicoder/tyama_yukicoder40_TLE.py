#!/usr/bin/python

def add(a,b):
	m=max(len(a),len(b))
	return [(0 if len(a)<=i else a[i])+(0 if len(b)<=i else b[i]) for i in range(m)]

def sub(a,b):
	return add(a,[-1*e for e in b])

def mul(a,b):
	r=[]
	for i in range(len(b)):
		r=add(r,[0]*i+[b[i]*e for e in a])
	return r

def checkio(b):
	'''
	b=[]
	for s in a:
		s=re.sub(r'-','Z',s)
		s=re.sub(r'x','0,1',s)
		b.append([int(_) for _ in process(s).split(',')])
	'''
	c=[]
	while len(b[1])<=len(b[0]):
		d=b[0][-1]//b[1][-1]
		c.append(d)
		b[0]=sub(b[0],[0]*(len(b[0])-len(b[1]))+[e*d for e in b[1]])
		assert b[0][-1]==0
		b[0].pop()
	while len(b[0])>1 and b[0][-1]==0: b[0].pop()
	print(len(b[0])-1)
	print(' '.join(str(e) for e in b[0]))

if __name__ == '__main__':
	import sys
	if sys.version_info[0]>=3: raw_input=input
	raw_input()
	checkio([[int(e) for e in raw_input().split()],[0,-1,0,1]])