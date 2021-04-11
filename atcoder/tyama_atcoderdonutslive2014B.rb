#!/usr/bin/ruby
n=gets.chomp
f=(n.to_i/10*10+1).step(n.to_i).find{|e|e%7==0}?1:0
p f+n.reverse[1..-1].each_char.with_index.reduce(0){|s,(c,i)|s+c.to_i*7**i}
