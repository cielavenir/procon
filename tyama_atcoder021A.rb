#!/usr/bin/ruby
m=4.times.map{gets.split.map(&:to_i)}
puts 4.times.any?{|i|3.times.any?{|j|m[i][j]==m[i][j+1]}} || 3.times.any?{|i|4.times.any?{|j|m[i][j]==m[i+1][j]}} ? :CONTINUE : :GAMEOVER