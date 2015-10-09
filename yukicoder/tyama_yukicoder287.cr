#!/usr/bin/env crystal
$memo={} of Tuple(Int32,Int32) => Int64
def perform(n,d,u)
	if d==1
		0<=n&&n<=u ? 1 : 0
	else
		if $memo.has_key?({n,d})
			return $memo[{n,d}]
		else
			$memo[{n,d}]=(0..u).inject(0_i64){|s,i|s+perform(n-i,d-1,u)}
		end
		# $memo[{n,d}]||=(0..u).inject(0_i64){|s,i|s+perform(n-i,d-1,u)}
	end
end
n=gets.not_nil!.to_i
p perform(6*n,8,n)