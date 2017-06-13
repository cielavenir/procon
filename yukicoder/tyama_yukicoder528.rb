#!/usr/bin/ruby
s=gets.chomp
n=s.size
m=-~n/2
a=n/2
p *[0,7].map{|d|(s[0,m].to_i+10**a-1-(s[0,a].reverse>s[m..-1] ? 1 : 0))%(d+10**9)}
