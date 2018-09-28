#!/usr/bin/ruby
while(s=gets.chomp)!='-'
gets.to_i.times{s+=s.slice!(0,gets.to_i)};puts s end