#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a=n.times.map{gets.split.map(&:to_i)}.transpose
1.step(m-1){|i|a[i][0]+=a[i-1][0]}
1.step(n-1){|j|a[0][j]+=a[0][j-1]}
1.step(m-1){|i|1.step(n-1){|j|a[i][j]=[a[i-1][j],a[i][j-1]].map{|e|e+a[i][j]}.max}}
puts a.last*' '