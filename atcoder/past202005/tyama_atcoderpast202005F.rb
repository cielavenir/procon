#!/usr/bin/ruby
n=gets.to_i
a=n.times.map{gets.chomp.chars}
n.times{|i|a[i]&=a[n-i-1]}
puts a.all?{|e|e.size>0} ? a.map{|e|e[0]}*'' : -1
