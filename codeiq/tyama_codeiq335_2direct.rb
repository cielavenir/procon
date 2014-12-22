#!/usr/bin/ruby
a=Array.new(n=gets.to_i){[]}
s="%#{(n*n).to_s.size}d"
a[n/=2][n]=1
1.step(n){|i|1.step(i*2){|j|z=(i*2-1)**2
a[n-i+j][n+i]=z+j
a[n+i][n+i-j]=z+i*2+j
a[n+i-j][n-i]=z+i*4+j
a[n-i][n-i+j]=z+i*6+j
}}
puts a.map{|e|e.map{|f|s%f}*' '}