#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

dot=lambda a,b: (a.conjugate()*b).real
norm=lambda a: a.real**2+a.imag**2

x1,y1,x2,y2,x3,y3=[int(e) for e in raw_input().split()]
a=[complex(x1,y1),complex(x2,y2),complex(x3,y3)]
base=None
p=None
for i in range(3):
	if dot(a[(i+1)%3]-a[i],a[(i+2)%3]-a[i])==0:
		p=[a[(i+1)%3]-a[i],a[(i+2)%3]-a[i]]
		base=a[i]
		break
if base is None or norm(p[0])!=norm(p[1]):
	print(-1)
	exit()
base+=p[0]+p[1]
print('%d %d'%(base.real,base.imag))
