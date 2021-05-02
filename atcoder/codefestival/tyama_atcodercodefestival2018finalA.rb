#!/usr/bin/ruby
h=Hash.new r=0
gets
$<.map{|e|
	a,b,c=e.split.map &:to_i
	r+=h[[a,2540-c]]+h[[b,2540-c]]
	h[[a,c]]+=1
	h[[b,c]]+=1
}
p r
