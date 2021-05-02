#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i)
left=[0]
right=[0]
s1=s2=t1=t2=0
n.times{|i|
	left<<s2+=i+s1+=a[i]
	right<<t2+=i+t1+=a[n-i-1]
}
p 0.step(n-1,2).map{|i|
	left[i]+right[n-i-1]
}.min