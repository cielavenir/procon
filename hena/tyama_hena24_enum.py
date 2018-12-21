#!/usr/bin/env python
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/
import sys
import itertools
from functools import partial,reduce

'''
from math import sqrt
try:
	#from scipy.special import cbrt # thx @ryosy383
	from numpy import cbrt
except ImportError:
	try:
		import ctypes
		if sys.platform.startswith('linux'):
			libm=ctypes.cdll.LoadLibrary('libm.so.6')
		elif sys.platform=='darwin':
			libm=ctypes.cdll.LoadLibrary('libSystem.dylib')
		elif sys.platform=='win32':
			libm=ctypes.cdll.LoadLibrary('msvcr120.dll')
		else:
			raise ImportError
		cbrt=lambda n:libm.cbrt(ctypes.c_double(n))
		libm.cbrt.restype=ctypes.c_double
	except ImportError:
		cbrt=lambda n: n**(1-2.0/3)
'''

def isqrt(n):
	if n<=0: return 0
	if n<4: return 1
	x,y=0,n
	while x!=y and x+1!=y:
		x,y=y,(n//y+y)//2
	return x
def icbrt(n):
	if n<0: return icbrt(-n)
	if n==0: return 0
	if n<8: return 1
	x,y=0,n
	while x!=y and x+1!=y:
		x,y=y,(n//y//y+y*2)//3
	return x

if sys.version_info[0]>=3: raw_input=input

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

is_sq=lambda n: isqrt(n)**2==n
is_cb=lambda n: icbrt(n)**3==n
is_multiple=lambda i,n: i%n==0
is_le=lambda i,n: i<=n

f={
	'S': partial(drop_next,is_sq),
	's': partial(drop_prev,is_sq),
	'C': partial(drop_next,is_cb),
	'c': partial(drop_prev,is_cb),
	'h': partial(drop_n,is_le,100),
}

#cf: https://twitter.com/closureobject/status/678619154346151941
for e in range(2,10): f[str(e)]=partial(drop_n,is_multiple,e) # OK
#for e in range(2,10): f[str(e)]=lambda n:drop_n(is_multiple,e,n) #NG
#for e in range(2,10): f[str(e)]=(lambda x:lambda n:drop_n(is_multiple,x,n))(e) # OK

if __name__=='__main__':
	try:
		while True:
			#cS => f['S'](f['c'](itertools.count(1)))
			'''
			print(','.join(
				map(str,itertools.islice(
					reduce(lambda s,e:f[e](s),raw_input().rstrip(),itertools.count(1)),
				10))
			))
			'''
			g=reduce(lambda s,e:f[e](s),raw_input().rstrip(),itertools.count(1))
			print(','.join(str(next(g)) for i in range(10)))
			sys.stdout.flush()
	except EOFError:
		pass
