#!/usr/bin/ruby
gets
s=gets
puts s.tr(([*?a..?z]-[s[gets.to_i-1]])*'','*'*25)
