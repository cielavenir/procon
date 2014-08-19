#!/usr/bin/ruby
p 1.step(gets.to_i*2-3,2).reduce(:*)%10**6