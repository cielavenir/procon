#!/usr/bin/ruby
p gets.to_i.times.reduce([2,1,1]){|(a,b,c),i|[a*(a+b*(a+a-b)),a*a+b*b*(a+a-b),3*c+a**3].map{|e|e%1000000007}}[2]