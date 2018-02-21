#!/usr/bin/ruby
a=$<.read.split.map &:to_i
puts (1...a.size).any?{|i|
	a[a[a[i]]]==i
} ? :YES : :NO
