#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map(&:to_i)
s=gets.chomp.bytes
r=0
n.times{|i|r+=a[i] if s[i]==66}
r0=r1=r
n.times{|i|
	if s[i]==65
		r0+=a[i]
	else
		r0-=a[i]
	end
	r=[r,r0].max
}
(n-1).downto(0){|i|
	if s[i]==65
		r1+=a[i]
	else
		r1-=a[i]
	end
	r=[r,r1].max
}
p r