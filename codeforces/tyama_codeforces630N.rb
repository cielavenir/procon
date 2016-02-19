#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_f)
(a=-a;b=-b;c=-c)if a<0
puts [1,-1].map{|s|(-b+s*Math.sqrt(b*b-4*a*c))/2/a}