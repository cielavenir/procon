#!/usr/bin/python
from sklearn.linear_model import LinearRegression
import sys
n,k=map(int,sys.stdin.readline().split())
a=[list(map(float,sys.stdin.readline().split())) for _ in range(k)]
b=[]
for i in range(k): b.append(a[i].pop())
clf=LinearRegression()
clf.fit(a,b)
for _ in range(int(sys.stdin.readline())):
	e=list(map(float,sys.stdin.readline().split()))
	print('%f'%clf.predict(e))
