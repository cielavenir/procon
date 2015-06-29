#!/usr/bin/ruby
#wget -O - https://projecteuler.net/project/resources/p022_names.txt
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