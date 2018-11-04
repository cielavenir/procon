#!/usr/bin/ruby
gets;s=gets.chomp.chars.uniq
puts s.size<2 ? :NO : "YES\n%s%s"%s[0,2]
