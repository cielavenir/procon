#!/usr/bin/ruby
n,c=gets.split.map(&:to_i)
a=n.times.map{gets.to_i}
mi=n
1.step(10){|i|
	1.step(10){|j|
		next if i==j
		m=n.times.count{|k|(k%2==0 ? i : j)!=a[k]}
		mi=m if mi>m
	}
}
p mi*c