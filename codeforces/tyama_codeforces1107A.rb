#!/usr/bin/ruby
n=gets.to_i
n.times{gets;s=gets.chomp;puts s[0].to_i>=s[1..-1].to_i ? :NO : "YES\n2\n%s %s"%[s[0],s[1..-1]]}
