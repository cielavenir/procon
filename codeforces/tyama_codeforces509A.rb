#!/usr/bin/env ruby
n=gets.to_i
a=[1]*n
(n-1).times{
	b=[1]
	1.upto(n-1){|j|
		b[j]=a[j]+b[j-1]
	}
	a=b
}
p a.max