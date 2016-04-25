#!/usr/bin/ruby
s=gets.chomp;p (z=s.index(?I))?(s[z..-1].squeeze.size+1)/2*2-1:0