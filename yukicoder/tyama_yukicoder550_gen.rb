#!/usr/bin/ruby
A,B,C=gets.split.map &:to_i
puts '%d %d %d'%[-(A+B+C),A*B+B*C+C*A,-A*B*C]
