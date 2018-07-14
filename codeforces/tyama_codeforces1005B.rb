#!/usr/bin/ruby
a,b=$<.map{|e|e.chomp.reverse}
las=[a.size,b.size].min
idx=(0...las).find{|i|a[i]!=b[i]}||las
p a.size+b.size-idx*2
