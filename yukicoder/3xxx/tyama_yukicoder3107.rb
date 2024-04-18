#!/usr/bin/ruby
n,m=gets.split.map &:to_i
r=[]
h={}
(1..m).each{|i|
x,y=gets.split.map &:to_i
(h[x]=h[y]=1;r<<i)if !h[x]&&!h[y]
}
p r.size
puts r
