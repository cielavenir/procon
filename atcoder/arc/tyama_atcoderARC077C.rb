#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
b=[]
a.each_with_index{|e,i|b.send([:push,:unshift][(i+n)%2],e)}
puts b*' '
