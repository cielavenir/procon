#!/usr/bin/env crystal
prm=2155
pri=[false]*(prm+1)
pr=[] of Int64
2.upto(prm){|i|
	if !pri[i]
		pr<<i.to_i64*i*i
		(i*2).step(prm,i){|j|
			pri[j]=true
		}
	end
}
h=Hash(Int64,Int32).new(0)
gets.not_nil!.to_i.times{
	n=gets.not_nil!.to_i64
	pr.each{|x|break if n<x;while n% x==0;n/=x end}
	h[n]+=1
}
visit=Set{1_i64}
r=[1,h[1_i64]].min
h.to_a.sort.each{|z|
	k,v=z
	next if visit.includes?(k)
	n=k*k
	pr.each{|x|break if n<x;n/=x if n% x==0}
	v=h[n] if v<h[n]
	r+=v
	visit.add(n)
}
p r