#!/usr/bin/ruby
s=gets
puts 'ACGT'.chars.map{|e|s.scan(/#{e}/).size}.join' '