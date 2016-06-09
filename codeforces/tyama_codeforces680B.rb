#!/usr/bin/ruby
n,k,*a=$<.read.split.map(&:to_i)
k-=1
r=[]
n.times{|i|
	h=[]
	if k-i>=0
		h.push(a[k-i]==0 ? nil : k-i)
	end
	if k+i<n
		h.push(a[k+i]==0 ? nil : k+i)
	end
	h.uniq!
	r+=h if h==h.compact
}
p r.size