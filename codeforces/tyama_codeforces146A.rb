#!/usr/bin/ruby
n=gets.to_i
s=gets.chomp
puts s=~/^[47]{#{n}}$/ && s[0,n/2].split('').map(&:to_i).reduce(:+)==s[n/2..-1].split('').map(&:to_i).reduce(:+) ? 'YES' : 'NO'