#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;a.sort!
b=[0]+n.times.map{|j|a[j]*(-1)**j%24}
s=24
n.times{|j|(j+1..n).each{|k|s=[s,(b[j]-b[k])%24,(b[k]-b[j])%24].min}}
p s
