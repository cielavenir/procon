#!/usr/bin/ruby
a,b,c=$<.map &:chomp
puts c.tr(a+a.upcase,b+b.upcase)
