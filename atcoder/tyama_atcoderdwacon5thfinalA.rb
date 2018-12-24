#!/usr/bin/ruby
n,m,k=gets.split.map &:to_i
s=gets.chomp.chars.map{|c|c<?R}
a=m.times.map{gets.split.map &:to_i}.transpose
y=[t=true]*n;x=[!t]*n;z=[!t]*n
[[s,x,t],[s,y,!t],[y,z,t]].each{|s,t,f|m.times{|i|2.times{|j|s[a[j][i]-1]==f&&t[a[j^1][i]-1]=f}}}
puts (k%2>0?x:z).map{|e|e ?:First: :Second}
