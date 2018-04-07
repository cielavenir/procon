#!/usr/bin/python
n,m,l,x=map(int,raw_input().split())
a=map(int,raw_input().split())
q=[1]+[float('inf')]*(m-1)
for i in range(n):
	q0=list(q)
	for j in range(m):
		t=j+a[i]
		q0[t%m]=min(q[t%m],q[j]+t/m)
	q=q0
print 'No' if q[l]>x else 'Yes'
