#!/usr/bin/ruby
n,a,b=gets.split.map &:to_i
s=t=0
gets.chomp.split('*').map(&:size).each{|x|s+=x/2;t+=x%2}
m=[a,s].min+[b,s].min
p m+[a+b-m,t].min
