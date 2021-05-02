#!/usr/bin/ruby
N,X=gets.split.map &:to_i
a=N.times.map{gets.split.map &:to_i}
r=Float::INFINITY
(1<<N).times{|i|
	s=X
	r0=0
	N.times{|j|
		if i[j]>0
			r0+=a[j][0]
			s-=a[j][0]*100*-~j+a[j][1]
		end
	}
	(N-1).downto(0){|j|
		if i[j]==0&&s>0
			k=100*-~j
			n=[(s+k-1)/k,a[j][0]].min
			r0+=n
			s-=n*k
		end
	}
	r=[r,r0].min
}
p r
