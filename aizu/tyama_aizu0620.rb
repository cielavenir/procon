#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a=$<.map(&:to_i)
1.upto(m){|f|
	(n-1).times{|i|a[i],a[i+1]=a[i+1],a[i] if a[i]%f>a[i+1]%f}
}
puts a