#!/usr/bin/ruby
a=gets.chomp.chars.chunk{|e|e}.to_a.transpose
puts a[0]*''=='abc'&&(a[1][0].size==a[1][2].size||a[1][1].size==a[1][2].size)?:YES: :NO
