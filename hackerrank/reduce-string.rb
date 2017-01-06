#!/usr/bin/ruby
s=gets.chomp
while s.sub!(/(.)\1/,'') do end
puts s.empty? ? 'Empty String' : s
