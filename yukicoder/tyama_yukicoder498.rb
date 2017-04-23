#!/usr/bin/ruby
M=10**9+7;I=[1,1];*F=I;*R=I
2.upto(99){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
def dfs(x,y,a)
	r=x!=W||y!=H||(!a.empty?&&a[-1]==0) ? 0 : F[a.reduce(0,:+)]*a.map{|e|R[e]}.reduce(1,:*)%M
	if a.size<A.size
		dx,dy,n=A[a.size]
		(0..n).each{|i|
			r=(r+dfs(x+dx*i,y+dy*i,a+[i]))%M
		}
	end
	r
end
W,H,K=gets.split.map &:to_i
A=K.times.map{gets.split.map &:to_i}
p dfs(0,0,[])
