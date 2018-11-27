#!/usr/bin/ruby
n=gets.to_i
i=2
i+=1 while i*i<n&&n%i>0
p 1+(i*i<=n ? (n-i)/2 : 0)
