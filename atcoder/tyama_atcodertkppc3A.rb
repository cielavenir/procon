#!/usr/bin/ruby
a,b=$<.map{|e|a=e.split;a[1].to_i*(a[0]==?W?-1:1)}
p (a-b).abs/15
