#!/usr/bin/ruby
require 'rational'
p 2.step(20).reduce(1){|s,i|s=s.lcm(i)}