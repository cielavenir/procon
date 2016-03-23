#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i)
b=a.group_by{|e|e}.map{|k,v|[-v.size,k]}.sort
c=b.take_while{|s,k|s==b[0][0]}.map(&:last)
h={}
a.reverse.each_with_index{|e,i|h[e]||=i if c.include?(e)}
p h.max_by{|k,v|v}[0]