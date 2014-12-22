#!/usr/bin/ruby
M=5
N=4
D=[[-1,0],[1,0],[0,-1],[0,1]]
raise 'Both M and N are odd, which is not supported yet' if (M*N).odd?

A=N.times.map{[nil]*M}
def dfs(sx,sy,x,y,d)
	return 0 if x<0 || M<=x || y<0 || N<=y || A[y][x]
	if d==M*N
		return 1 #sx+sy*M<x+y*M ? 1 : 0
	end
	r=0
	A[y][x]=1
=begin
	#こっちだと5*6で28秒。やはり配列アクセスが遅い。
	D.each{|dir|
		r+=dfs(sx,sy,x+dir[0],y+dir[1],d+1)
	}
=end
	r+=dfs(sx,sy,x-1,y,d+1)
	r+=dfs(sx,sy,x+1,y,d+1)
	r+=dfs(sx,sy,x,y-1,d+1)
	r+=dfs(sx,sy,x,y+1,d+1)
	A[y][x]=nil
	return r
end
r=0
#先に半分にすることで、5*6でも18秒に。
(M*N/2).times{|i|
	sx=i%M
	sy=i/M
	r+=dfs(sx,sy,sx,sy,1)
}
p r #1006