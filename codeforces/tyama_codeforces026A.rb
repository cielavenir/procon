#!/usr/bin/ruby
require 'prime'
a=[0,0]+2.step(3001).map{|e|x=e.prime_division;x.size==2 ? 1 : 0}
p a[0..gets.to_i].reduce(:+)