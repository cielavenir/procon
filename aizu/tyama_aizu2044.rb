#!/usr/bin/ruby
while(a,b,c=gets.split.map(&:to_i))!=[-1,-1,-1]
if 2.step(16).none?{|base|begin Integer(a.to_s(base))==b rescue nil end} then p -1;next end
(a+1).step(c){|i|b=2.step(16).map{|base|begin z=i.to_s(base).to_i;b<=z ? z : 1e9 rescue 1e9 end}.min}
p b
end