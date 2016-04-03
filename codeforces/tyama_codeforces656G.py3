#!/usr/bin/python
f,kitten,n=map(int,input().split())
a=zip(*[input() for _ in range(f)])
print(sum(sum(f=='Y' for f in e)>=n for e in a))