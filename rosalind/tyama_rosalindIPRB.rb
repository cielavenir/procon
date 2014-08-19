#!/usr/bin/ruby
k,m,n=gets.split.map(&:to_i)
N=(k+m+n).to_f
p 1-1/N/(N-1)*(n*(n-1)+n*m+m*(m-1)/4.0)