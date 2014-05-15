#!/usr/bin/ruby
B=gets.split
a=gets.to_i.times.map{gets.chomp}
puts a.sort{|a,b|(l=a.size<=>b.size)==0&&a.size.times.all?{|i|(l=B.index(a[i])<=>B.index(b[i]))==0};l}