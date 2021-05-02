#!/usr/bin/ruby
(n,m,c),b,*a=$<.map{|e|e.split.map &:to_i}
p a.count{|e|e.zip(b).reduce(c){|s,(x,y)|s+x*y}>0}
