#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

def chk(grid,x,y,n):
	siz=2*(n-1)+1
	for i in range(-n+1,n):
		a='o'*(2*(n-abs(i)-1)+1)
		start_point=x-len(a)//2
		for j in range(len(a)):
			if 0<=y+i<len(grid) and 0<=start_point+j<len(grid[0]) and grid[y+i][start_point+j]!=a[j]: return False
	return True

r,c,k=[int(e) for e in raw_input().split()]
grid=[raw_input().rstrip() for i in range(r)]
ret=0
for i in range(k-1,c-k+1):
	for j in range(k-1,r-k+1):
		if chk(grid,i,j,k): ret+=1
print(ret)