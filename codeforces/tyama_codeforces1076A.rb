#!/usr/bin/ruby
n=gets.to_i
s=gets
i=(0...n).find{|i|s[i]>s[i+1]}
puts s[0,i]+s[i+1..-1].chomp
