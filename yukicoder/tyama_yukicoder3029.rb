#!/usr/bin/ruby
puts [:even,:odd][(5**47-1)/4%gets.to_i%2]
