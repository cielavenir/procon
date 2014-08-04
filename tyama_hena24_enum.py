#!/usr/bin/env python
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/
import sys
import math
import itertools
from functools import partial,reduce
from scipy.special import cbrt # thx @ryosy383

'''
def generate():
	i=1
	while True:
		yield i
		i+=1
'''

def drop_prev_square(prev):
	a=next(prev)
	b=next(prev)
	while True:
		if int(math.sqrt(float(b)))**2!=b: yield a
		a,b=b,next(prev)

def drop_next_square(prev):
	a=next(prev)
	b=next(prev)
	yield a
	while True:
		if int(math.sqrt(float(a)))**2!=a: yield b
		a,b=b,next(prev)

def drop_prev_cubic(prev):
	a=next(prev)
	b=next(prev)
	while True:
		if int(cbrt(float(b)))**3!=b: yield a
		a,b=b,next(prev)

def drop_next_cubic(prev):
	a=next(prev)
	b=next(prev)
	yield a
	while True:
		if int(cbrt(float(a)))**3!=a: yield b
		a,b=b,next(prev)

def drop_num(n,prev):
	i=0
	while True:
		i+=1
		a=next(prev)
		if i%n!=0: yield a

def drop_cnt(n,prev):
	i=0
	while True:
		i+=1
		a=next(prev)
		if i>n: yield a

f={
	'S': drop_next_square,
	's': drop_prev_square,
	'C': drop_next_cubic,
	'c': drop_prev_cubic,
	'h': partial(drop_cnt,100),
}
for e in range(2,10): f[str(e)]=partial(drop_num,e)

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