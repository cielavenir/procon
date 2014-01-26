#!/usr/bin/ruby
require'rational'
gets;x=gets.split.map(&:to_i).reduce(&:gcd)
m={}
1.step(Math.sqrt(x).to_i){|i|m[i]=m[x/i]=1 if x%i==0}
puts m.keys.sort