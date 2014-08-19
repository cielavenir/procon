#!/usr/bin/ruby
puts ' '+(1..gets.to_i).select{|i|i%3==0||i.to_s.include?('3')}*' '