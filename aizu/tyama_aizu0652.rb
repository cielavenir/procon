#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
s=0
p (1..1/0.0).find{|i|
	s+=a
	s+=b if i%7==0
	s>=c
}
