#!/usr/bin/ruby
a,b,c=0,1,1;gets.to_i.times{a,b,c=b,c,(a+b)%1000000007};p c