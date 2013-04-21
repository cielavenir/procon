#!/usr/bin/ruby
B=gets.chomp.split
a=gets.to_i.times.map{gets.chomp}
puts a.sort{|a,b|(l=a.length<=>b.length)==0&&a.length.times.all?{|i|(l=B.index(a[i])<=>B.index(b[i]))==0};l}