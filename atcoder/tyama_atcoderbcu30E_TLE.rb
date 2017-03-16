#!/usr/bin/ruby
def dfs(r,c,n,k)
	return if $visited[[r,c]]
	$visited[[r,c]]=1
	if r>0 && $f[r-1][c]%2>0 #k.times.all?{|i|$s[r-1][c+i]=='.'}
		$uf.unite([r,c],[r-1,c])
		dfs(r-1,c,n,k)
	end
	if r<n-k && $f[r+k][c]%2>0 #k.times.all?{|i|$s[r+k][c+i]=='.'}
		$uf.unite([r,c],[r+1,c])
		dfs(r+1,c,n,k)
	end
	if c>0 && $f[r][c-1]/2>0 #k.times.all?{|i|$s[r+i][c-1]=='.'}
		$uf.unite([r,c],[r,c-1])
		dfs(r,c-1,n,k)
	end
	if c<n-k && $f[r][c+k]/2>0 #k.times.all?{|i|$s[r+i][c+k]=='.'}
		$uf.unite([r,c],[r,c+1])
		dfs(r,c+1,n,k)
	end
end
class UnionFind
	def initialize
		@parent={}
	end
	def root(a)
		@parent[a]=a if !@parent.has_key?(a)
		return @parent[a]==a ? a : (@parent[a]=root(@parent[a]))
	end
	def unite(a,b)
		x=root(a)
		y=root(b)
		@parent[x]=y
	end
	def has_key?(a)
		@parent.has_key?(a)
	end
end

n,k,q=gets.split.map(&:to_i)
$s=n.times.map{gets.chomp}
$f=n.times.map{[0]*n}
(n-1).downto(0){|r|
	cnt=0
	(n-1).downto(0){|c|
		if $s[r][c]=='.'
			cnt+=1
			$f[r][c]|=1 if cnt>=k
		else
			cnt=0
		end
	}
}
(n-1).downto(0){|c|
	cnt=0
	(n-1).downto(0){|r|
		if $s[r][c]=='.'
			cnt+=1
			$f[r][c]|=2 if cnt>=k
		else
			cnt=0
		end
	}
}
$visited={}
$uf=UnionFind.new
q.times{
	r1,c1,r2,c2=gets.split.map(&:to_i)
	r1-=1
	c1-=1
	r2-=1
	c2-=1
	if !$uf.has_key?([r1,c1])
		dfs(r1,c1,n,k)
	end
	if !$uf.has_key?([r2,c2])
		dfs(r2,c2,n,k)
	end
	puts $uf.root([r1,c1])==$uf.root([r2,c2]) ? :Yes : :No
}
