#!/usr/bin/ruby
require 'prime'
h={}
2.step(36){|i|h[i]=i.prime_division}
p h