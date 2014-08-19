#!/usr/bin/ruby
while gets
a,b=$_.split.map(&:to_i)
x=[*a..b].map{|e|e.to_s==e.to_s.reverse ? 1 : 0}
p 1.step(b-a+1).reduce(0){|s,w|s+=x.each_cons(w).count{|y|y.reduce(:+)%2==0}}
end