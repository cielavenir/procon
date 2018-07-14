#!/usr/bin/ruby
_,a,b=$<.map{|e|e.split.map &:to_i}
r=0
a.each{|e|b[r].to_i>=e&&r+=1}
p r
