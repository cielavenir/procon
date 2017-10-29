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

n,m=gets.split.map(&:to_i)
deg=Hash.new 0
uf=UnionFind.new
m.times{
	a,b=gets.split.map(&:to_i)
	deg[a]^=1
	deg[b]^=1
	uf.unite(a,b)
}
puts uf.keys.all?{|k|uf.root(k)==uf.root(uf.each_key.next)}&&deg.values.all?{|e|e<=1}&&deg.values.count{|e|e==1}<3 ? :YES : :NO
