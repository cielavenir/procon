#!/usr/bin/env python3
#coding:utf-8

# _xxsubinterpreters https://vstinner.github.io/isolate-subinterpreters.html

#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/
import sys
import itertools
from functools import partial,reduce

### test.support.interpreters causes segmentation fault, so I have to use my own high-level function. ###
import _xxsubinterpreters
from time import sleep
from os.path import basename
from os.path import dirname
from os.path import realpath
from threading import Thread
def recv(id, _sentinel=object(), _delay=10.0 / 1000):  # 10 milliseconds
	obj = _xxsubinterpreters.channel_recv(id, _sentinel)
	while obj is _sentinel:
		sleep(_delay)
		obj = _xxsubinterpreters.channel_recv(id, _sentinel)
	return obj
def send_nowait(id, obj):
	_xxsubinterpreters.channel_send(id, obj)
channel_create = _xxsubinterpreters.channel_create
channel_close = _xxsubinterpreters.channel_close
create = _xxsubinterpreters.create
run_string = _xxsubinterpreters.run_string
interp_list = []
def myrun(fname,scid,rcid):
	interp = create(isolated=True)
	interp_list.append(interp)
	caller_module = basename(__file__).split('.')[0]  # todo use frame
	t = Thread(target=run_string,args=(interp,f"""
import sys
sys.dont_write_bytecode = True
sys.path.append('{dirname(realpath(__file__))}')
from {caller_module} import *
{fname}(scid,rcid)
""",dict(scid=scid,rcid=rcid)))
	t.start()
###

def isqrt(n):
	if n<=0: return 0
	if n<4: return 1
	x,y=0,n
	while x!=y and x+1!=y:
		x,y=y,(n//y+y)//2
	return x
def icbrt(n):
	if n<0: return -icbrt(-n)
	if n==0: return 0
	if n<8: return 1
	x,y=0,n
	while x!=y and x+1!=y:
		x,y=y,(n//y//y+y*2)//3
	return x

if sys.version_info[0]>=3: raw_input=input

def generate(scid,rcid):
	try:
		i=1
		while i<10000:
			# --with-experimental-isolated-subinterpretersを使えばTrueで良いはずだが、高頻度でSEGVとなる。
			send_nowait(scid,i)
			i+=1
	except _xxsubinterpreters.ChannelClosedError:
		pass

def drop_prev(check,scid,rcid):
	try:
		a=recv(rcid)
		b=recv(rcid)
		while True:
			if not check(b): send_nowait(scid,a)
			a,b=b,recv(rcid)
	except _xxsubinterpreters.ChannelClosedError:
		pass

def drop_next(check,scid,rcid):
	try:
		a=recv(rcid)
		b=recv(rcid)
		send_nowait(scid,a)
		while True:
			if not check(a): send_nowait(scid,b)
			a,b=b,recv(rcid)
	except _xxsubinterpreters.ChannelClosedError:
		pass

def drop_n(check,n,scid,rcid):
	try:
		i=0
		while True:
			i+=1
			a=recv(rcid)
			if not check(i,n): send_nowait(scid,a)
	except _xxsubinterpreters.ChannelClosedError:
		pass

is_sq=lambda n: isqrt(n)**2==n
is_cb=lambda n: icbrt(n)**3==n
is_multiple=lambda i,n: i%n==0
is_le=lambda i,n: i<=n

impl_S=partial(drop_next,is_sq)
impl_s=partial(drop_prev,is_sq)
impl_C=partial(drop_next,is_cb)
impl_c=partial(drop_prev,is_cb)
impl_h=partial(drop_n,is_le,100)
impl_2=partial(drop_n,is_multiple,2)
impl_3=partial(drop_n,is_multiple,3)
impl_4=partial(drop_n,is_multiple,4)
impl_5=partial(drop_n,is_multiple,5)
impl_6=partial(drop_n,is_multiple,6)
impl_7=partial(drop_n,is_multiple,7)
impl_8=partial(drop_n,is_multiple,8)
impl_9=partial(drop_n,is_multiple,9)

if __name__=='__main__':
	try:
		while True:
			first = True
			line = raw_input().rstrip()
			cids = []
			for e in line:
				if first:
					rcid = channel_create()
					cids.append(rcid)
					myrun('generate',scid=rcid,rcid=None)
					first = False
				rcid2 = channel_create()
				cids.append(rcid2)
				myrun('impl_'+e,scid=rcid2,rcid=rcid)
				rcid = rcid2
			print(','.join(str(recv(rcid)) for i in range(10)))
			sys.stdout.flush()
			for cid in cids:
				channel_close(cid, force=True)
	except EOFError:
		pass
