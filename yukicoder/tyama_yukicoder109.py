#!/usr/bin/python
for _ in range(input()):
	n,m=map(int,raw_input().split())
	a=0
	b=1
	while b*-~b<=m:
		b+=1
		if m%b<1:
			if n<b+m/b:
				a=1
				while n:
					a=a*n%m
					n-=1
			break
	else:
		if n<m:
			b=1
			n+=1
			while n<m:
				b=b*n%m
				n+=1
			a=(m-1)*pow(b,max(n-2,0),m)%m
	print(a)