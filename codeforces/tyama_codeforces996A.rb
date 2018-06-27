#!/usr/bin/ruby
r=0
n=gets.to_i
[100,20,10,5,1].each{|e|
	k,n=n.divmod(e)
	r+=k
}
p r
