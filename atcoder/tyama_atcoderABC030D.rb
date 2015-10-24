#!/usr/bin/ruby
n,a=gets.split.map(&:to_i)
k=gets.to_i
b=[0]+gets.split.map(&:to_i)
h={}
c=a
i=0
loop{
	if h.has_key?(b[c])
		cycle=i-h[b[c]]
		#k+=h[b[c]]
		k%=cycle
		break
	end
	c=b[c]
	h[c]=i
	i+=1
	k-=1
	if k==0
		p c
		exit
	end
}
k.times{c=b[c]}
p c