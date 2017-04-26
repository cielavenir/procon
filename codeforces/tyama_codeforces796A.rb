#!/usr/bin/ruby
n,m,k,*a=$<.read.split.map(&:to_i)
b=a.map.with_index(1){|e,i|0<e&&e<=k ? i : nil}.compact
p 10*b.map{|i|(i-m).abs}.min
