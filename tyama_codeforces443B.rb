#!/usr/bin/ruby
s=gets.chomp
k=gets.to_i
l=s.size
m=l+k
m=m-m%2
if k>=l
	p m
else
	ma=0
	l.times{|i|
		1.step(l-i){|j|
			if 2*j>ma && i.step(i+j-1).all?{|o|(o+j>=l&&o+j<l+k)||s[o]==s[o+j]}
				ma=2*j
			end
		}
	}
	p ma
end