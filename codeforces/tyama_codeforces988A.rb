#!/usr/bin/ruby
n,k,*a=$<.read.split.map &:to_i
r=[];h={}
a.each.with_index(1){|e,i|!h[e]&&h[e]=1&&r<<i}
if r.size>=k
	puts :YES
	puts r[0,k]*' '
else
	puts :NO
end
