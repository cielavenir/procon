#!/usr/bin/ruby
#wget -O - http://projecteuler.net/project/names.txt
s=gets.chomp
a=eval('['+s+']').sort
r=0
a.length.times{|i|
	x=0
	a[i].each_byte{|n|x+=n-64}
	r+=x*(i+1)
}
p r