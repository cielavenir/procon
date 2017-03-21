#!/usr/bin/ruby
s=gets.chomp.reverse.chars.map &:to_i
p (1..s.size).bsearch{|m|
	x=m*9;g=0;s.all?{|c|(0<=x-=(x+g-c)%10)&&g=(x+g)/10}
}
