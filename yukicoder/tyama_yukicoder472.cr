#!/usr/bin/env crystal
def dfs(
	memo : Hash(Array(Int32),Int32),
	v : Array(Array(Int32)),
	d : Int32,
	r : Int32
)
	return 0_i32 if d==v.size
	memo[[d,r]]||=(0..[r,3].min).reduce(1_i32<<60){|s,i|
		[s,dfs(memo,v,d+1,r-i)+v[d][i]].min
	}
end
memo=Hash(Array(Int32),Int32).new
n,k=gets.not_nil!.split.map(&.to_i)
v=n.times.map{gets.not_nil!.split.map(&.to_i)+[1_i32]}.to_a
p dfs(memo,v,0,k) / n.to_f
