#!/usr/bin/ruby
n,x,*a=`dd`.split.map &:to_i
p n+(x-=a.reduce :+)/a.min
