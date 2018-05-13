#!/usr/bin/ruby
ENV[Z='RUBY_THREAD_VM_STACK_SIZE']||exec({Z=>?5*8},'ruby',$0)
require 'set'
def dfs(z,c)
	f=S[c]
	r=[0,c]
	G[c].each{|e|
		next if e==z
		t=dfs(c,e)
		r=[r,[t[0]+f,t[1]]].max
	}
	r
end
N=gets.to_i
G=Hash.new{|h,k|h[k]=Set.new}
(N-1).times{
	a,b=gets.split.map(&:to_i)
	G[a-1]<<b-1
	G[b-1]<<a-1
}
A=gets.chomp
(p A.count(?W);exit) if A.count(?W)<2
r=N-1
Q=N.times.select{|i|G[i].size==1&&A[i]==?B}
while !Q.empty?
	c=Q.shift
	r-=1
	G[c].each{|e|
		G[e].delete c
		Q<<e if G[e].size==1&&A[e]==?B
	}
	G.delete c
end
r*=2
S={}
G.keys.each{|k|
	if G[k].empty?
		G.delete k
	else
		r+=S[k]=((A[k]==?B?0:1)+G[k].size)%2
	end
}
p r-dfs(-1,dfs(-1,G.each_key.first)[1])[0]*2
