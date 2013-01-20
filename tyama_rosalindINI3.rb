#!/usr/bin/ruby
s=gets
r=[]
gets.split.map(&:to_i).each_slice(2){|a,b|r<<s[a..b]}
puts r.join' '