#!/usr/bin/ruby
require 'prime'
h={1=>0}
a=[1,1]
3.step(51){|i|
	b=Array.new(i)
	b[0]=b[i-1]=1
	1.step(i-2){|j|
		b[j]=a[j-1]+a[j]
	}
	a=b
	1.step(i/2){|j|
		h[a[j]] || h[a[j]]=a[j].prime_division.count{|a,b|b>1}
	}
}
p h.select{|k,v|v==0}.keys.reduce(:+)