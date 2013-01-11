#!/usr/bin/ruby
#wget -O - http://projecteuler.net/project/roman.txt
s=''
while gets do s<<$_ end
z=s.length
s.gsub!('IIII','IV')
s.gsub!('XXXX','XL')
s.gsub!('CCCC','CD')
s.gsub!('VIV','IX')
s.gsub!('LXL','XC')
s.gsub!('DCD','CM')
p z-s.size