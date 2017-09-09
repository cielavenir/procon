#!/usr/bin/ruby
N=gets.to_i
m=(0..N).map{[0]*7};m[0][0]=1.0
N.times{|i|6.times{|j|m[i+1][j+1]=m[i][j]*(6-j)/6.0+m[i][j+1]*-~j/6}}
p m[N][6]
