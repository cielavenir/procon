#!/usr/bin/ruby
p 999999.times.map{|i|s,t=i.to_s,i.to_s(2);s.reverse==s&&t.reverse==t ?i:0}.reduce(:+)