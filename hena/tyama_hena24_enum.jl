#!/usr/bin/env julia

# http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
# http://nabetani.sakura.ne.jp/hena/ord24eliseq/

function isqrt(n::Int)
	if n<=0
		return 0
	end
	if n<4
		return 1
	end
	local x=0
	local y=n
	while x!=y&&x+1!=y
		x=y
		y=(n÷y+y)÷2
	end
	return x
end

function icbrt(n::Int)
	if n<0
		return icbrt(-n)
	end
	if n==0
		return 0
	end
	if n<8
		return 1
	end
	local x=0
	local y=n
	while x!=y&&x+1!=y
		x=y
		y=(n÷y÷y+y*2)÷3
	end
	return x
end

function is_sq(n::Int)
	local x=isqrt(n)
	return x*x==n
end
function is_cb(n::Int)
	local x=icbrt(n)
	return x*x*x==n
end
is_multiple(i::Int,n::Int) = i%n==0
is_le(i::Int,n::Int) = i<=n

function generate()
	local ch = Channel{Int}(8)
	function _producer()
		local i=1
		while true
			put!(ch,i)
			i+=1
		end
	end
	@async _producer()
	ch
end

function drop_prev(check::Function,prev::Channel{Int})
	local ch = Channel{Int}(8)
	function _producer()
		local a=take!(prev)
		local b=take!(prev)
		while true
			if !check(b)
				put!(ch,a)
			end
			a=b
			b=take!(prev)
		end
	end
	@async _producer()
	return ch
end

function drop_next(check,prev::Channel{Int})
	local ch = Channel{Int}(8)
	function _producer()
		local a=take!(prev)
		local b=take!(prev)
		put!(ch,a)
		while true
			if !check(a)
				put!(ch,b)
			end
			a=b
			b=take!(prev)
		end
	end
	@async _producer()
	return ch
end

function drop_n(check,n::Int,prev::Channel{Int})
	local ch = Channel{Int}(8)
	function _producer()
		local i=0
		while true
			i+=1
			a=take!(prev)
			if !check(i,n)
				put!(ch,a)
			end
		end
	end
	@async _producer()
	return ch
end

Base.@ccallable function julia_main(args::Vector{String})::Cint
	local f=Dict(
		'S' => prev -> drop_next(is_sq,prev),
		's' => prev -> drop_prev(is_sq,prev),
		'C' => prev -> drop_next(is_cb,prev),
		'c' => prev -> drop_prev(is_cb,prev),
		'h' => prev -> drop_n(is_le,100,prev)
	)
	for j in 2:9
		#ラムダ式のキャプチャはバグらないみたいですね
		f[j+'0']=prev -> drop_n(is_multiple,j,prev)
	end

	local line=readline(stdin)
	while line!=""
		line=rstrip(line)
		#cS => f['S'](f['c'](generate()))
		local ch = generate()
		for c in line
			ch=f[c](ch)
		end
		for i in 0:9
			if i>0
				print(",")
			end
			a=take!(ch)
			print(a)
		end
		print("\n")
		flush(stdout)
		line=readline(stdin)
	end
	return 0
end

if get(ENV, "COMPILE_STATIC", "false") == "false"
	julia_main(ARGS)
end
