#!/usr/bin/env python
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/
import sys
import itertools
from functools import partial,reduce
from math import sqrt
from scipy.special import cbrt # thx @ryosy383

'''
def generate():
	i=1
	while True:
		yield i
		i+=1
'''

def drop_prev(check,prev):
	a=next(prev)
	b=next(prev)
	while True:
		if not check(b): yield a
		a,b=b,next(prev)

def drop_next(check,prev):
	a=next(prev)
	b=next(prev)
	yield a
	while True:
		if not check(a): yield b
		a,b=b,next(prev)

def drop_n(check,n,prev):
	i=0
	while True:
		i+=1
		a=next(prev)
		if not check(i,n): yield a

is_sq=lambda n: int(sqrt(float(n)))**2==n
is_cb=lambda n: int(cbrt(float(n)))**3==n
is_multiple=lambda i,n: i%n==0
is_le=lambda i,n: i<=n

f={
	'S': partial(drop_next,is_sq),
	's': partial(drop_prev,is_sq),
	'C': partial(drop_next,is_cb),
	'c': partial(drop_prev,is_cb),
	'h': partial(drop_n,is_le,100),
}
for e in range(2,10): f[str(e)]=partial(drop_n,is_multiple,e)

if __name__=='__main__':
	try:
		while True:
			print(','.join(map(str,
				list(itertools.islice(
					reduce(lambda s,e:f[e](s),raw_input().rstrip(),itertools.count(1)),
				10))
			)))
	except EOFError:
		pass