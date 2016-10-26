#!/usr/bin/ruby
T='fedabc'
s=gets.chomp
x=T.index(s[-1])+1
s=s.to_i-1
d,r=s.divmod(4)
if r%2==1
	x+=7
end
p x+d*16
