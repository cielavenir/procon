#!/usr/bin/ruby
a,b,c=2,1,1;gets.to_i.times{a,b,c=[a*(a+b*(d=a+a-b)),a*a+b*b*d,3*c+a**3].map{|e|e%(10**9+7)}};p c