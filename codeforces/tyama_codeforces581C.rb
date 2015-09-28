#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
a=gets.split.map(&:to_i).sort_by{|e|0-e%10}
a.size.times{|i|
	y=10-a[i]%10
	next if y==10
	x=[y,k].min
	a[i]+=x
	k-=x
}
a.size.times{|i|
	y=100-a[i]
	next if y==0
	x=[y,k].min
	a[i]+=x
	k-=x
}
p a.map{|e|e/10}.reduce(:+)