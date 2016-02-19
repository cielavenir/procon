#!/usr/bin/ruby
a,b,c=gets.split.map &:to_f;p (a**3/12+b**3/6)*Math.sqrt(2)+c**3*(5+Math.sqrt(5))/24