#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
a*=b
r=0
a.times{|i|r+=a/(i+1.0)}
p r