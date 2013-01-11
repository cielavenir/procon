#!/usr/bin/ruby
c=Hash.new{|h,k|h[k]=[]}
(1..1/0.0).each{|i|k=(i**3).to_s.split('').sort;if c[k].push(i**3).size==5 then p c[k][0];exit end}