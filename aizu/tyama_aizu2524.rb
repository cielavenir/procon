#!/usr/bin/ruby
s=gets.chomp;p s.size.times.count{|i|l=(s[0,i]||0).to_i;r=(s[i..-1]||0).to_i;(s[i,1]!='0'||i==s.size-1)&&l<=r&&l%2==r%2}