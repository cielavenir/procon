#!/usr/bin/ruby
N,K,*a=$<.read.split.map(&:to_i)
r=0
N.times{
	(N-K).times{|i|
		if a[i]>a[i+K]
			a[i],a[i+K]=a[i+K],a[i]
			r+=1
		end
	}
}
p (0..N-2).all?{|i|a[i]<a[i+1]} ? r : -1