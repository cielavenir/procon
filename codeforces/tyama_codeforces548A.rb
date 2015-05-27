#!/usr/bin/env ruby
s=gets.chomp
k=gets.to_i
puts s.size%k==0 && k.times.all?{|i|t=s[s.size/k*i,s.size/k];t==t.reverse} ? :YES : :NO