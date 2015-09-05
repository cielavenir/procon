#!/usr/bin/ruby
def dfs(n,d,z)
	r=nil
	H[n].each{|e|
		if !z.has_key?(e)
			z[e]=1
			r||=1<<29
			x=dfs(e,d+1,z)
			r=[r,x+1].min
			z.delete(e)
		end
	}
	r||=0
	R[n]=[r,d].min
	L[n]=r
	r
end
def dfs2(n,d,z)
	H[n].each{|e|
		if !z.has_key?(e)
			z[e]=1
			dfs2(e,[d,L[n]].min+1,z)
			z.delete(e)
		end
	}
	R[n]=[R[n],d].min
end
		
n=gets.to_i
H=Hash.new{|h,k|h[k]=[]}
R={}
L={}
(n-1).times{
	x,y=gets.split.map(&:to_i)
	H[x]<<y
	H[y]<<x
}
dfs(1,0,{1=>1})
dfs2(1,0,{1=>1})
1.step(n){|i|p R[i]}