#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
p n*-~n/2-a.chunk{|e|e}.map{|v,a|v>0?a.size*-~a.size/2:0}.sum
