#!/usr/bin/ruby
s=gets.chomp.sub(/0+$/,'')
puts s==s.reverse ? :YES : :NO
