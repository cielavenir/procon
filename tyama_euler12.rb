#!/usr/bin/ruby
require 'prime'
(1..1/0.0).each{|e|if (t=e*(e+1)/2).prime_division.reduce(1){|s,e|s*=e[1]+1} > 500 then p t;exit end}