#!/usr/bin/env crystal
Memo=Hash(Int32,Int64).new
def f(n,k,m)
	return 1_i64 if n==0 || k==0
	Memo[n*1000+k]||=(1..n).reduce(0_i64){|s,j|
		(s+B[n-1][j-1]*f(j,k-1,m)%m*f(n-j,k,m))%m
	}
end
n,k,m=gets.not_nil!.split.map(&.to_i)
B=[[1_i64]]
(1..300).each{|i|B<<[1_i64]+B[i-1].each_cons(2).map{|(x,y)|(x+y)%m}.to_a+[1_i64]}
puts f(n+1,k-1,m)
