#!/usr/bin/ruby
a=(1..n=gets.to_i).zip
0.step(n/=2){|i|0.step(z=i*2){|j|x,y=i,i-j;4.times{|k|a[n-y][n+x]='%*d'%[4-21/(n+6),(z+k-2)*z+j+1];x,y=y,-x}}}
puts a.map{|e|e*' '}