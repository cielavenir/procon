#!/usr/bin/ruby
a=Array.new(n=gets.to_i){[]}
a[n/=2][n]=(k=1)
1.step(n){|i|1.step(i*2){|j|a[n-i+j][n+i]=(k+=1)}
1.step(i*2){|j|a[n+i][n+i-j]=(k+=1)}
1.step(i*2){|j|a[n+i-j][n-i]=(k+=1)}
1.step(i*2){|j|a[n-i][n-i+j]=(k+=1)}
}
puts a.map{|e|e.map{|f|"%#{k.to_s.size}d"%f}*' '}