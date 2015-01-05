#!/usr/bin/ruby
h=Hash.new(0)
gets.downcase.chars{|c|h[c]+=1}
puts (('a'..'z').all?{|c|h[c]>0}?'':'not ')+'pangram'