#!/usr/bin/env lua
-- http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
-- http://nabetani.sakura.ne.jp/hena/ord24eliseq/

-- require 'mathx' -- luarocks install lmathx

function isqrt(n)
	if n<=0 then
		return 0
	end
	if n<4 then
		return 1
	end
	local x=0
	local y=n
	while x~=y and x+1~=y do
		x=y
		y=(n//y+y)//2
	end
	return x
end
function icbrt(n)
	if n<0 then
		return icbrt(-n)
	end
	if n==0 then
		return 0
	end
	if n<8 then
		return 1
	end
	local x=0
	local y=n
	while x~=y and x+1~=y do
		x=y
		y=(n//y//y+y*2)//3
	end
	return x
end

function generate()
	return coroutine.create(function()
		local i=1
		while true do
			coroutine.yield(i)
			i=i+1
		end
	end)
end
function drop_prev(check,prev)
	return coroutine.create(function()
		local a,b
		_,a=coroutine.resume(prev)
		_,b=coroutine.resume(prev)
		while true do
			if not check(b) then
				coroutine.yield(a)
			end
			a=b
			_,b=coroutine.resume(prev)
		end
	end)
end
function drop_next(check,prev)
	return coroutine.create(function()
		local a,b
		_,a=coroutine.resume(prev)
		_,b=coroutine.resume(prev)
		coroutine.yield(a)
		while true do
			if not check(a) then
				coroutine.yield(b)
			end
			a=b
			_,b=coroutine.resume(prev)
		end
	end)
end
function drop_n(check,n,prev)
	return coroutine.create(function()
		local i=0,a
		while true do
			i=i+1
			_,a=coroutine.resume(prev)
			if not check(i,n) then
				coroutine.yield(a)
			end
		end
	end)
end

function is_sq(n)
	-- local x=math.floor(math.sqrt(n))
	local x=isqrt(n)
	return x*x==n
end
function is_cb(n)
	-- local x=math.floor(math.cbrt(n))
	local x=icbrt(n)
	return x*x*x==n
end
function is_multiple(i,n)
	return i%n==0
end
function is_le(i,n)
	return i<=n
end

local f={
	['S']=function(e) return drop_next(is_sq,e) end,
	['s']=function(e) return drop_prev(is_sq,e) end,
	['C']=function(e) return drop_next(is_cb,e) end,
	['c']=function(e) return drop_prev(is_cb,e) end,
	['h']=function(e) return drop_n(is_le,100,e) end,
}
local i,r
for i=2,9 do
	f[tostring(i)]=function(e) return drop_n(is_multiple,i,e) end
end
local line=io.read('*line')
while line~=nil do
	local g=generate()
	for c in line:gmatch('.') do
		g=f[c](g)
	end
	for i=1,10 do
		if i>1 then
			io.write(',')
		end
		_,r=coroutine.resume(g)
		io.write(r)
	end
	io.write("\n")
	io.flush()
	line=io.read('*line')
end
