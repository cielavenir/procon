#!/usr/bin/ruby
r=0
gets
gets.split.each{|e|r+=[0,80-e.to_i].max}
p r