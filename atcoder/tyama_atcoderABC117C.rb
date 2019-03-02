#!/usr/bin/ruby
k,n,*a=`dd`.split.map &:to_i;p a.sort.each_cons(2).map{|x,y|y-x}.min([n-k,0].max).reduce 0,:+
