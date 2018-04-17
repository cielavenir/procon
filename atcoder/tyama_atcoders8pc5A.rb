#!/usr/bin/ruby
n,t,*a=`dd`.split.map &:to_i
r=0
a.each{|e|
	r=e.step(9**9,t).find{|f|f>=r}
}
p r
