#!/usr/bin/ruby
N,M,*X=`dd`.split.map(&:to_i)
h=Hash.new{|h,k|h[k]=[]}
X.each{|e|h[e%M]<<e}
r=0
q=[0]*M
(0...M).each{|i|
	opp=M-i
	opp=0 if opp==M
	if i==opp
		s=h[i].size/2
		q[i]=s*2
	else
		s=[h[i].size,h[opp].size].min
		q[i]=q[opp]=s
	end
	t=h[i].group_by{|e|e}.reduce(0){|s,(k,v)|s+v.size/2}
	r+=[(h[i].size-q[i])/2,t].min
	i<=M/2&&r+=s
}
p r
