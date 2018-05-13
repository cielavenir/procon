#!/usr/bin/ruby
class UnionFind < Hash
	def root(a)
		self[a]=a if !has_key?(a)
		return self[a]==a ? a : (self[a]=root(self[a]))
	end
	def unite(a,b)
		x=root(a)
		y=root(b)
		self[x]=y
	end
end
uf=UnionFind.new
n,m=gets.split.map &:to_i
q=gets.split.map &:to_i
m.times{
	x,y=gets.split.map &:to_i
	uf.unite(x,y)
}
h=Hash.new{|h,k|h[k]=[]}
g=Hash.new{|g,k|g[k]=[]}
(1..n).each{|i|
	h[uf.root(i)]<<q[i-1]
	g[uf.root(i)]<<i
}
r=0
h.each_key{|k|r+=(h[k]&g[k]).size}
p r
