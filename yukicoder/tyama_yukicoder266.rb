#!/usr/bin/ruby
gets;S=gets.split.map &:to_i
m=[0]+[1e9]*S[-1]
S.map{|s|0.upto(s){|j|m[j]+=1;s.times{|x|m[j]=[m[j],m[x]+m[j-1-x]].min}}}
$><<m*' '