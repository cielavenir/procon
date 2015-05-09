#!/usr/bin/env ruby
k=gets.to_i
s=gets.chomp
h={}
s.each_byte.with_index{|c,i|h[c]||=i}
if h.size<k
	puts :NO
else
	puts :YES
	puts (h.to_a[0,k].map(&:last)+[s.size]).each_cons(2).map{|x,y|s[x...y]}
end