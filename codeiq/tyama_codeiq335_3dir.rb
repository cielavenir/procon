#!/usr/bin/ruby
a=Array.new(n=gets.to_i){[]}
s="%#{(n*n).to_s.size}d"
a[n/=2][n]=s%1
1.step(n){|i|1.step(i*2){|j|d=[[-i+j,i],[i,i-j],[i-j,-i],[-i,-i+j]]
4.times{|k|a[n+d[k][0]][n+d[k][1]]=s%[(i*2-1)**2+j+i*2*k]}}}
puts a.map{|e|e*' '}