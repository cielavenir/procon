#!/usr/bin/ruby
n=gets.to_i
a=Array.new(n){[]}
a[n/2][n/2]=(k=1)
3.step(n,2){|i|
	(i-1).times{|j|a[n/2-i/2+1+j][n/2+i/2]=(k+=1)}
	(i-1).times{|j|a[n/2+i/2][n/2+i/2-1-j]=(k+=1)}
	(i-1).times{|j|a[n/2+i/2-1-j][n/2-i/2]=(k+=1)}
	(i-1).times{|j|a[n/2-i/2][n/2-i/2+1+j]=(k+=1)}
}
puts a.map{|e|e.map{|f|"%#{k.to_s.size}d"%f}*' '}