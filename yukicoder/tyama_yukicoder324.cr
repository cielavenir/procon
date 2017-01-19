#!/usr/bin/env crystal
MIN=-100000000
Memo=Array(Int32).new(40000000,MIN)
def dfs(n,w,z,prev,cur,remain)
	key=z*20000000+prev*10000000+cur*3100+remain
	if remain<0 || remain>n-cur
		MIN
	elsif cur==n
		w[cur-1]*prev*z
	elsif Memo[key]!=MIN
		Memo[key]
	else
		r1=dfs(n,w,z,0,cur+1,remain)
		r2=dfs(n,w,z,1,cur+1,remain-1)+w[cur-1]*prev
		Memo[key] = r1>r2 ? r1 : r2
	end
end
n,m=gets.not_nil!.split.map(&.to_i)
w=gets.not_nil!.split.map(&.to_i)
if m<2
	p 0
else
	r1=dfs(n,w,0,0,1,m)
	r2=dfs(n,w,1,1,1,m-1)
	p r1>r2 ? r1 : r2
end
