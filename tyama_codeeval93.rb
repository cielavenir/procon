#!/usr/bin/ruby
puts$<.map{|l|l.split.map{|e|a=e.split('');a.shift.upcase+a*''}*' '}