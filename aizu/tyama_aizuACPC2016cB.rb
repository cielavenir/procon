#!/usr/bin/ruby
n,m,*a=$<.read.split.map(&:to_i)
r=a.select{|e|e>m}.map{|e|e-m}.reduce(0,:+)
puts r>0 ? r : :kusoge
