#!/usr/bin/ruby
#Based on
#https://twitter.com/tsurara_R/status/838389966681985025
#http://yahoo-procon2017-qual.contest.atcoder.jp/submissions/1146154
g=->a,b{l=[a.size,b.size].min;(0...l).find{|i|a[i]!=b[i]}||l}
n,k=gets.split.map &:to_i
n==k&&exit
a={};gets.split.each{|e|a[e.to_i]=1}
s=n.times.map{|i|[gets.chomp,i+1]}.sort
l,r=[n.times,(n-1).downto(0)].map{|z|z.find{|i|a.include?(s[i][1])}}
s=s.map{|e|e[0]}
m=[g[s[l-1].to_s,s[l]],g[s[r+1].to_s,s[r]]].max+1
z=g[s[l],s[r]]
puts m>z||a.size<r-l+1?-1:s[l][0,m]
