#!/usr/bin/ruby
n,*a=$<.map &:to_i
n.times{a=a.each_slice(2).map{|x,y|x>y ?x-y :x<y ?y-x :x}}
p *a
