#!/usr/bin/env crystal
Memo={} of Tuple(Int32,Int32) => Int64
def perform(n,d,u)
	if d==1
		0<=n&&n<=u ? 1 : 0
	else
		Memo[{n,d}]||=(0..u).reduce(0_i64){|s,i|s+perform(n-i,d-1,u)}
	end
end
n=gets.not_nil!.to_i
p perform(6*n,8,n)
