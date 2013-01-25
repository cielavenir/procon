#!/usr/bin/ruby
puts gets.split.map{|e|1-(1-Math.sqrt(e.to_f))**2}*' '