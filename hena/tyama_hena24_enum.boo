#!/usr/bin/env booi
#http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
#http://nabetani.sakura.ne.jp/hena/ord24eliseq/
import System
import System.Linq.Enumerable
import System.Collections.Generic

def isqrt(n as int) as int:
	if n<=0: return 0
	if n<4: return 1
	x,y=0,n
	while x!=y and x+1!=y:
		x,y=y,(n/y+y) / 2
	return x
def icbrt(n as int) as int:
	if n<0: return icbrt(-n)
	if n==0: return 0
	if n<8: return 1
	x,y=0,n
	while x!=y and x+1!=y:
		x,y=y,(n/y / y+y*2) / 3
	return x

def generate() as IEnumerable[of int]:
	i=1
	while true:
		yield i
		i+=1

def drop_prev(check as Func[of int,bool],_prev as IEnumerable[of int]) as IEnumerable[of int]:
	prev=_prev.GetEnumerator()
	prev.MoveNext()
	a=prev.Current
	prev.MoveNext()
	b=prev.Current
	while true:
		if not check(b): yield a
		prev.MoveNext()
		a,b=b,prev.Current

def drop_next(check as Func[of int,bool],_prev as IEnumerable[of int]) as IEnumerable[of int]:
	prev=_prev.GetEnumerator()
	prev.MoveNext()
	a=prev.Current
	prev.MoveNext()
	b=prev.Current
	yield a
	while true:
		if not check(a): yield b
		prev.MoveNext()
		a,b=b,prev.Current

def drop_n(check as Func[of int,int,bool],n as int,_prev as IEnumerable[of int]) as IEnumerable[of int]:
	prev=_prev.GetEnumerator()
	i=0
	while true:
		i+=1
		prev.MoveNext()
		a=prev.Current
		if not check(i,n): yield a

is_sq={n as int|(x=isqrt(n))*x==n}
is_cb={n as int|(x=icbrt(n))*x*x==n}
is_multiple={i as int,n as int|i%n==0}
is_le={i as int,n as int|i<=n}

f=Dictionary[of char,Func[of IEnumerable[of int],IEnumerable[of int]]]()
f[char('S')]={x|drop_next(is_sq,x)}
f[char('s')]={x|drop_prev(is_sq,x)}
f[char('C')]={x|drop_next(is_cb,x)}
f[char('c')]={x|drop_prev(is_cb,x)}
f[char('h')]={x|drop_n(is_le,100,x)}

for e in range(2,10):f[48+e]={x|{n|drop_n(is_multiple,x,n)}}(e)

while true:
	line=Console.ReadLine()
	if line==null: break
	first=true
	#cS => f['S'](f['c'](generate()))
	for n in line.Aggregate(generate(),{s,e|f[e](s)}).Take(10):
		if not first: Console.Write(',')
		first=false
		Console.Write(n)
	Console.WriteLine()
	Console.Out.Flush()
