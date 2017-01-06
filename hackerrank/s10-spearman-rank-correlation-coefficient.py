#!/usr/bin/python
import sys,scipy.stats
n=int(sys.stdin.readline())
a=list(map(float,sys.stdin.readline().split()))
b=list(map(float,sys.stdin.readline().split()))
print('%.3f'%scipy.stats.spearmanr(a,b)[0])
