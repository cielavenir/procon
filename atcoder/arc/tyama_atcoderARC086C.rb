#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i
h=Hash.new 0
a.each{|e|h[e]+=1}
h=h.sort_by{|k,v|-v}.map &:last
p (h[k..-1]||[]).reduce 0,:+
