#!/usr/bin/ruby
k=gets.to_i
s=gets.chomp
h=0
s.size.times{|i|h+=k**i*(s[i].ord-96)}
t=''.dup
while h>0
	z=h%k
	z=k if z==0
	z+=k while z+k<=[h,26].min
	t<<(96+z).chr
	h-=z
	h/=k
end
puts t
