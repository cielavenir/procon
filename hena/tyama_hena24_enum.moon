#!/usr/bin/env moon
-- http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
-- http://nabetani.sakura.ne.jp/hena/ord24eliseq/

isqrt=(n)->
	if n<=0
		return 0
	if n<4
		return 1
	x=0
	y=n
	while x!=y and x+1!=y
		x=y
		y=(n//y+y)//2
	x

icbrt=(n)->
	if n<0
		return icbrt(-n)
	if n==0
		return 0
	if n<8
		return 1
	x=0
	y=n
	while x~=y and x+1~=y
		x=y
		y=(n//y//y+y*2)//3
	x

generate=->
	coroutine.create(->
		i=1
		while true
			coroutine.yield(i)
			i=i+1
	)

drop_prev=(check,prev)->
	coroutine.create(->
		_,a=coroutine.resume(prev)
		_,b=coroutine.resume(prev)
		while true do
			if not check(b)
				coroutine.yield(a)
			a=b
			_,b=coroutine.resume(prev)
	)

drop_next=(check,prev)->
	return coroutine.create(->
		_,a=coroutine.resume(prev)
		_,b=coroutine.resume(prev)
		coroutine.yield(a)
		while true
			if not check(a)
				coroutine.yield(b)
			a=b
			_,b=coroutine.resume(prev)
	)

drop_n=(check,n,prev)->
	return coroutine.create(->
		i=0
		while true
			i=i+1
			_,a=coroutine.resume(prev)
			if not check(i,n)
				coroutine.yield(a)
	)

is_sq=(n)->
	-- x=math.floor(math.sqrt(n))
	x=isqrt(n)
	return x*x==n

is_cb=(n)->
	-- x=math.floor(math.cbrt(n))
	x=icbrt(n)
	return x*x*x==n

is_multiple=(i,n)->i%n==0

is_le=(i,n)->i<=n

f={
	['S']:(e)->drop_next(is_sq,e),
	['s']:(e)->drop_prev(is_sq,e),
	['C']:(e)->drop_next(is_cb,e),
	['c']:(e)->drop_prev(is_cb,e),
	['h']:(e)->drop_n(is_le,100,e),
}

-- ラムダ周りのカッコは必要(forがラムダの中にかかってしまう)
f[tostring(i)]=((e)->drop_n(is_multiple,i,e)) for i=2,9

line=io.read('*line')
while line!=nil
	g=generate()
	g=f[c](g) for c in line\gmatch('.')
	for i=1,10
		io.write(',') if i>1
		_,r=coroutine.resume(g)
		io.write(r)
	io.write("\n")
	io.flush()
	line=io.read('*line')
