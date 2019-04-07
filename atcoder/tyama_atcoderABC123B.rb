#!/usr/bin/ruby
a=$<.map(&:to_i).sort_by{|e|-e%10}
(a.size-1).times{|i|a[i]=(a[i]+9)/10*10}
p a.reduce :+
