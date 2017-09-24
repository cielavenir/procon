#!/usr/bin/ruby
n=gets.to_i
a=[]
s=0
$<.map{|e|x,y=e.split.map &:to_i;s+=y;a<<x+y}
a.sort!
p n.times.find{|i|0>s-=a[i]}||n
