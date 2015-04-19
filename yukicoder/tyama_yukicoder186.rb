#!/usr/bin/ruby
a=$<.map{|e|e.split.map &:to_i}
x,y=a[0]
p (1..2).each{|j|
f=(0..a[j][1]).find{|i|x+y*i>0&&(x+y*i)%a[j][1]==a[j][0]}
break if !f
x=x+y*f
y=a[j-1][1].lcm a[j][1]
}?x:-1