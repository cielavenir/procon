#!/usr/bin/ruby
s=gets.chomp
1while s.sub!(/(.)\1/,'')
puts s.empty? ? 'Empty String' : s
