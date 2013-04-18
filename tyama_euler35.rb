#!/usr/bin/ruby
require 'prime';
h={};a=[]
Prime.each(999999){|e|h[e]=1;a<<e.to_s}
p a.count{|s|s.length.times.map{|i|h[(s[i,s.length-i]+s[0,i]).to_i]}.all?}