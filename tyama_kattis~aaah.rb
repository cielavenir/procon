#!/usr/bin/ruby
a,b=$<.map(&:chomp)
puts a.size<b.size ? :no : :go