#!/usr/bin/ruby
r=0
gets.chomp.bytes{|b|
	r+=b-65+1 if 65<=b&&b<=90
	r-=b-97+1 if 97<=b&&b<=122
}
p r