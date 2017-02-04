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
	r
end
def dfs(x,a,b)
	ch=F[x]||=children(x)
	r=[nil]*3
	q=ch.map{|e|dfs(e,a,b)}
	q.each{|a,b,c|
		r[0]=[r[0]||Float::INFINITY,a+1].min if a
		r[1]=[r[1]||Float::INFINITY,b+1].min if b
		r[2]=[r[2]||Float::INFINITY,c].min if c
	}
	r[0]=0 if x==a
	r[1]=0 if x==b
	r[2]=[r[2]||Float::INFINITY,r[0]+r[1]].min if r[0]&&r[1]
	r
end
while gets
	x,a,b=$_.scan(/\d+/).map(&:to_i)
	p dfs(x,a,b)[2]||-1
	STDOUT.flush
end
