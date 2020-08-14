#!/usr/bin/env crystal
def dfs(
	v : Array(Array(Int32)),
	d : Int32,
	r : Int32
) : Int32
	return 0_i32 if d==v.size
	Memo[d*20000+r]||=(0..[r,3].min).reduce(1_i32<<30){|s,i|
		[s,dfs(v,d+1,r-i)+v[d][i]].min
	}
end
Memo=Hash(Int32,Int32).new
n,k=gets.not_nil!.split.map(&.to_i)
v=(0...n).map{gets.not_nil!.split.map(&.to_i)+[1_i32]}.to_a
p dfs(v,0,k) / n.to_f
