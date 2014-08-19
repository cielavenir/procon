#!/usr/bin/ruby
require 'prime'
h={1=>0}
a=[1]
2.step(51){|i|
	a=[1]+a.each_cons(2).map{|x,y|x+y}+[1]
	1.step(i/2){|j|
		h[a[j]] || h[a[j]]=a[j].prime_division.count{|a,b|b>1}
	}
}
p h.select{|k,v|v==0}.keys.reduce(:+)