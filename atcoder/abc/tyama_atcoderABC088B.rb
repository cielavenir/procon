#!/usr/bin/ruby
a=`sed 1d`.split.map(&:to_i).sort_by(&:-@)
r=0
a.each_with_index{|e,i|r+=e*(-1)**i}
p r
