#!/usr/bin/ruby
class SAComp
	def initialize(h,g)
		@h=h;@g=g
	end
	def call(a,b)
		return 0 if a==b
		return @g[a]-@g[b] if @g[a]!=@g[b]
		@g[a+@h]-@g[b+@h]
	end
end
def buildSA(t)
	n=t.size
	g=t.each_byte.to_a
	b=[0]*n
	comp=SAComp.new(0,g)
	suff=(0...n).sort(&comp.method(:call))
	h=1
	while b[n-1]!=n-1
		comp=SAComp.new(h,g)
		suff.sort!(&comp.method(:call))
		(n-1).times{|i|b[i+1]=b[i]+(comp.(suff[i],suff[i+1])<0?1:0)}
		n.times{|i|g[suff[i]]=b[i]}
		h<<=1
	end
	suff
end
def buildLCP(t,suff)
	n=t.size
	rank=[0]*n
	lcp=[0]*n
	n.times{|i|rank[suff[i]]=i}
	h=0
	(n-1).times{|i|
		j=suff[rank[i]-1]
		h-=1 if h>0
		h+=1 while j+h<n && i+h<n && t[j+h]==t[i+h]
		lcp[rank[i]-1]=h
	}
	lcp
end
	
s=gets.chomp+'$'
suff=buildSA(s)
lcp=buildLCP(s,suff)
p s.size-1-lcp.max
