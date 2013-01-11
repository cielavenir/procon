#!/usr/bin/ruby
while gets
a,b=$_.split.map(&:to_i)
x=[*(a..b)].map{|e|e.to_s==e.to_s.reverse ? 1 : 0}
r=0
1.step(b-a+1){|w|x.each_cons(w){|y|r+=y.reduce(:+)%2==0 ? 1 : 0}}
p r
end