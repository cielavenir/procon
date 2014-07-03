#!/usr/bin/ruby
#https://github.com/rubyworks/facets/pull/92
class Array
	def unique_permutation(n=self.size)
		return to_enum(:unique_permutation,n) unless block_given?
		return if n<0||self.size<n
		a=self.sort
		yield a[0,n]
		loop{
			a=a[0,n]+a[n..-1].reverse
			k=(a.size-2).downto(0).find{|i|a[i]<a[i+1]}
			break if !k
			l=(a.size-1).downto(k+1).find{|i|a[k]<a[i]}
			a[k],a[l]=a[l],a[k]
			a=a[0,k+1]+a[k+1..-1].reverse
			yield a[0,n]
		}
	end
end

D=[[0,1],[1,0],[0,-1],[-1,0]]
M=5
N=4

def dfs(a,s,x,y,c)
	if x<0 || M<=x || y<0 || N<=y || a[y][x]!=c || s.include?([x,y])
		return 0
	end
	s[[x,y]]=1
	r=1
	D.each{|e|r+=dfs(a,s,x+e[0],y+e[1],c)}
	return r
end

surface=M*N
raise "M*N is odd" if surface.odd?
surface/=2
A=['*']*surface+['.']*surface
p A.unique_permutation.count{|_a|
	x=_a.index('*')
	y=_a.index('.')
	next if x>y
	x=[x%M,x/M]
	y=[y%M,y/M]
	a=_a.each_slice(M).to_a
	#a.each{|e|puts e*' '}
	sx=dfs(a,{},x[0],x[1],'*')
	sy=dfs(a,{},y[0],y[1],'.')
	sx==surface && sy==surface
} # 245