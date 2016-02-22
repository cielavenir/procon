#!/usr/bin/ruby
gets;a=$<.map{|e|e.chomp.chars}
r=0
[a,a.transpose].each{|b|b.each{|e|n=e.count('C');r+=n*(n-1)/2}}
p r