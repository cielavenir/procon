#!/usr/bin/python
def comb(n,r):
	if r==0: return 1
	ret=1
	if r>n//2: r=n-r
	for i in range(r):
		ret=ret*(n-i)/(i+1)
	return ret

def popcnt32(n):
	m1=0x55555555
	m2=0x33333333
	m4=0x0f0f0f0f
	m8=0x00ff00ff
	m16=0x0000ffff
	n=((n>>1)&m1)+(n&m1)
	n=((n>>2)&m2)+(n&m2)
	n=((n>>4)&m4)+(n&m4)
	n=((n>>8)&m8)+(n&m8)
	n=((n>>16)&m16)+(n&m16)
	return n

if 'maketrans' in str.__dict__:
	maketrans=str.maketrans
	raw_input=input
else:
	from string import maketrans

n=int(raw_input())
digits=2
while True:
	s=0
	five=2
	while five<=digits:
		s+=comb(digits,five)
		five+=3
	if n<=s: break
	n-=s
	digits+=1

i=1
while True:
	if popcnt32(i)%3==2:
		n-=1
		if n==0:
			print(('{:0'+str(digits)+'b}').format(i).translate(maketrans('01','35'))+'5')
			break
	i+=1