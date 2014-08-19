#!/usr/bin/ruby
def x(s)s.size>1&&s[0..0]=='X'end
while(l=gets)
l=~/([0-9X]+)\+([0-9X]+)=([0-9X]+)/
a=$1+'+'+$2+'=='+$3
puts :NA if ((x($1)||x($2)||x($3))?1:0).step(9).none?{|i|if eval(a.gsub('X',i.to_s)) then p i;true end}end