#!/usr/bin/ruby
def cycle(n) (1..1/0.0).each{|i| if ((10**i)-1)%n==0 then return i end} end
p 1.step(999,2).map{|i|[i%10==5?0:cycle(i),i]}.max[1]