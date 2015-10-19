#!/usr/bin/ruby
#gets;p ([0]+gets.split.map{|e|e.to_i+1}.sort+[0]).each_cons(2).map(&:max).reduce(:+)-1
gets;a=gets.split.map(&:to_i);p a.size+a.max+a.reduce(:+)