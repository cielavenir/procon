#!/usr/bin/ruby
a,b=gets.split
idx=(1...a.size).find{|i|a[i]>=b[0]}||a.size
puts a[0...idx]+b[0]
