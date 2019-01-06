#!/usr/bin/ruby
n=gets.to_i
s=gets.split.map &:to_i
(n-1).times{
a=gets.split.map &:to_i
s=[a[0]+[s[1],s[2]].max,a[1]+[s[0],s[2]].max,a[2]+[s[0],s[1]].max]
}
p s.max
