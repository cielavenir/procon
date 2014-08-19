#!/usr/bin/ruby
while gets
a=$_.split(',').map(&:to_i)
r=0
a.combination(4){|e|r+=1 if e.reduce(:+)==0} if a.size>3
p r
end