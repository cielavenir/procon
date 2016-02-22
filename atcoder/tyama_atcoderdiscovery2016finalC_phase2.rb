#!/usr/bin/ruby
M=1000000007

def parse(s,i)
	iorig=i-1
	r=[]
	while i<s.size
		if s[i]=='('
			a,b,n=parse(s,i+1)
			r<<[a,b]
			i=n+1
		else
			break
		end
	end
	[[iorig,i],r,i]
end

def dfs(memo,a,d,n)
	if d==a.size
		return n.abs<=K ? {n=>1} : {}
	else
		#this memoization is definitely awful
		memo[[d,n]]||=lambda{
			r=Hash.new(0)
			a[d].each{|k,v|dfs(memo,a,d+1,n+k).each{|k_,v_|r[k_]=(r[k_]+v_*v)%M}}
			r
		}.call
	end
end

def f(tree)
	if tree[1].empty?
		K<2 ? {0=>2} : {-2=>1,0=>2,2=>1}
	else
		a=tree[1].map{|e|f(e)}
		memo={}
		r=Hash.new(0)
		{-2=>1,0=>2,2=>1}.each{|k,v|dfs(memo,a,0,k).each{|k_,v_|r[k_]=(r[k_]+v_*v)%M}}
		p memo
		r
	end
end

s=gets.chomp
K=gets.to_i
#raise if s.size>100
a,b,n=parse('('+s+')',1)
p b.map{|e|f(e).values.reduce(:+)}.reduce(:*)%M