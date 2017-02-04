#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde11tredis/
#http://qiita.com/Nabetani/items/10b2ccc28301e44e09e6

F={}
def children(x)
	return [] if x<4
	r=[]
	i=2
	while i*i<=x
		if x%i==0
			r<<i+1
			r<<x/i+1 if i*i<x
		end
		i+=1
	end
	r # sort is not required
end
def dfs(x,a,b)
	ch=F[x]||=children(x)
	r={:l=>nil,:r=>nil,:t=>nil}
	q=ch.map{|e|dfs(e,a,b)}
	q.each{|e|
		r[:l]=[r[:l]||Float::INFINITY,e[:l]+1].min if e[:l]
		r[:r]=[r[:r]||Float::INFINITY,e[:r]+1].min if e[:r]
		r[:t]=[r[:t]||Float::INFINITY,e[:t]].min if e[:t]
	}
	r[:l]=0 if x==a
	r[:r]=0 if x==b
	r[:t]=[r[:t]||Float::INFINITY,r[:l]+r[:r]].min if r[:l]&&r[:r]
	r
end
while gets
	x,a,b=$_.scan(/\d+/).map(&:to_i)
	p dfs(x,a,b)[:t]||-1
	STDOUT.flush
end
