#!/usr/bin/ruby
n=gets.to_i
q=Math.sqrt(n).to_i
p n<3?0:q**2!=n ?-1:2.step(q).reduce(0){|s,i|s+=i*i-i+1}