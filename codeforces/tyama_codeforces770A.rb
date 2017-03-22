#!/usr/bin/ruby
n,k=gets.split.map &:to_i
b=[*'a'..'z'][0,k]
a=[]
a+=b while a.size<n
puts a[0,n]*''
