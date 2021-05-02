#!/usr/bin/ruby
a,b,c,x=$<.map &:to_i;a+=b+c;puts a<=x&&x<=a+3?:Yes: :No
#puts [a,a+1].product([b,b+1],[c,c+1]).any?{|e|e.reduce(:+)==x} ? :Yes : :No
