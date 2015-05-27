#!/usr/bin/ruby
h=Hash.new(0)
gets
$<.map{|e|e.split.map(&:to_i)}.transpose.each{|x,y|h[-y]+=x}
puts h.max_by{|k,v|[v,k]}[0]==0 ? :YES : :NO