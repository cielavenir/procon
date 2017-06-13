#!/usr/bin/ruby
bag=[1]
s=0
gets.to_i.times{
	v,w=gets.split.map(&:to_i)
	(s+=w).downto(w){|i|
		bag[i]=[bag[i]||0,(bag[i-w]||0)+v].max
	}
}
v=gets.to_i
idx=bag.index(v+1)
p idx<1 ? 1 : idx
idx=(idx...bag.size).find{|i|(bag[i]||0)>v+1}
puts idx ? idx-1 : :inf
