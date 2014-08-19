#!/usr/bin/ruby
s=gets.chomp.split('')
print :IN if s.size<6||['0'..'9','A'..'Z','a'..'z'].any?{|x|s.none?{|e|x.include?(e)}}
puts :VALID