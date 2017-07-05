#!/usr/bin/ruby
n,k=gets.split.map &:to_i
m=n/2/-~k
p m,k*m,n-m*-~k
