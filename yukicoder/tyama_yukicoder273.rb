#!/usr/bin/ruby
s=gets.chomp
l=s.size
r=1
0.upto(l-1){|i|i.upto(l-1){|j|
	next if i==0 and j==l-1
	r=[r,j-i+1].max if s[i..j]==s[i..j].reverse
}}
p r