#!/usr/bin/python
def f(a):
	q=a[:n];s=sum(q);heapify(q);yield s
	for e in a[n:2*n]:s+=e-heappushpop(q,e);yield s
from heapq import*;r=reversed;n,*a=map(int,open(0).read().split());print(max(map(sum,zip(f(a),r(list(f([-e for e in r(a)])))))))
