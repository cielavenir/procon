#!/usr/bin/ruby
L=gets.split.map &:to_i
s=0
3.times.map{|i|L[i]+L[(i+1)%3]}.sort.zip(gets.split.map(&:to_i).sort.reverse){|x,y|s+=x*y}
p s*2