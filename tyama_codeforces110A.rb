#!/usr/bin/ruby
n=gets.chomp.chars.count{|c|c=='4'||c=='7'}
puts n==4||n==7 ? :YES : :NO