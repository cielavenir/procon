#!/usr/bin/ruby
n,t=gets.split.map(&:to_i)
gets.split.map(&:to_i).each{|e|t-=e.to_i}
p t<10*(n-1) ? -1 : t/5