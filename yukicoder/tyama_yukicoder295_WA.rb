#!/usr/bin/ruby
S=gets.split.map(&:to_i)
h=[0]*26
gets.chomp.bytes{|b|
	h[b-97]+=1
}
res=1
S.size.times{|i|
	next if h[i]==0
	d,r=S[i].divmod(h[i])
	#p [S[i],h[i],d,r]
	h[i].times{|j|
		res*=d+(j<r ? 1 : 0)
		if res>=2**62
			puts :hel
			exit
		end
	}
}
p res