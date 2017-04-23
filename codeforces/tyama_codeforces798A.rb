#!/usr/bin/ruby
s=gets.chomp
t=s.reverse
n=s.size.times.count{|i|s[i]!=t[i]}
puts n==2||(n==0&&s.size%2==1) ? :YES : :NO
