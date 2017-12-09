#!/usr/bin/ruby
T=777
n,m=gets.split.map &:to_i
a=[0]*n
m.times{
	b=gets.split.map &:to_i
	n.times{|i|a[i]+=b[i]}
	h=t=x=0
	while h<n
		while h<n&&x<T
			x+=a[h]
			h+=1
		end
		break if x<T
		while t<n&&x>T
			x-=a[t]
			t+=1
		end
		if x==T
			puts :YES
			exit
		end
	end
}
puts :NO
