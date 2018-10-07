#!/usr/bin/ruby
n,m,a,b=gets.split.map &:to_i
i=0
while n>0
n-=a-1<=i%12&&i%12<a+b-1 ? 2*m : m
i+=1
end
p i
