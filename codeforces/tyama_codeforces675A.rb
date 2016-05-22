#!/usr/bin/ruby
a,b,c=gets.split.map(&:to_i)
puts b==a || (c!=0 && ((b>a) ^ (c<0))&&(b-a)%c==0) ? :YES : :NO