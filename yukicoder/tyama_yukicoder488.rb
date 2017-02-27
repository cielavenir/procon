#!/usr/bin/ruby
h=Hash.new{|h,k|h[k]=[]}
n,m=gets.split.map(&:to_i)
m.times{
	x,y=gets.split.map(&:to_i)
	h[x]<<y
	h[y]<<x
}
p [*0..n].combination(4).count{|a0|
	a0[0,3].permutation.any?{|a|
		a+=[a0[3]]
		h[a[0]].include?(a[1]) &&
		h[a[1]].include?(a[2]) &&
		h[a[2]].include?(a[3]) &&
		h[a[3]].include?(a[0]) &&
		!h[a[0]].include?(a[2]) &&
		!h[a[1]].include?(a[3])
	}
}
