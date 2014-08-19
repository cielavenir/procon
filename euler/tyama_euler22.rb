#!/usr/bin/ruby
#wget -O - http://projecteuler.net/project/names.txt
require 'json'
s=gets.chomp
a=JSON.parse('['+s+']').sort
r=0
a.size.times{|i|
	x=0
	a[i].each_byte{|n|x+=n-64}
	r+=x*(i+1)
}
p r