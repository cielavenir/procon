#!/usr/bin/ruby
n,m,k=gets.split.map &:to_i
t=m.times.map{_,*a,r=gets.split;[a.map{|e|1<<(e.to_i-1)}.sum,r=='o']}
p (1<<n).times.count{|i|t.all?{|a,r|r==(i&a).to_s(2).count('1')>=k}}
