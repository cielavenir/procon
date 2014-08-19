#!/usr/bin/ruby
require 'prime'
h={}
Prime.each(10**4+10){|e|h[e]=1}
p gets.to_i.times.count{e=gets.to_i;h[e]||h.keys.none?{|f|e%f==0}}