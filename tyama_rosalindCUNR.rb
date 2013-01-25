#!/usr/bin/ruby
p 1.step(gets.to_i*2-5,2).reduce(:*)%10**6