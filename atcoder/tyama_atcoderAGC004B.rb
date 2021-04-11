#!/usr/bin/ruby
n,x,*a=`dd`.split.map &:to_i;b=a.dup;p n.times.map{|i|t=x*i;n.times{|j|t+=b[j]=[b[j],a[(j-i)%n]].min};t}.min