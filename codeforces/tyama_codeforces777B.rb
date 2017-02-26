#!/usr/bin/ruby
n=gets.to_i
a,b=$<.map{|e|e.chomp.bytes.sort}
j=0
p n-b.count{|e|e>=a[j]&&j+=1}
j=0
p b.count{|e|e>a[j]&&j+=1}
