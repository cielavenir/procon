#!/usr/bin/ruby
T=[[1,1],[0,1],[-1,1],[1,0],[-1,0],[0,-1]]
D={[0,0]=>0}
Q=[[0,0]]
X={}
n,x,y=gets.split.map &:to_i
n.times{
	u,v=gets.split.map &:to_i
	X[[u,v]]=1
}
loop{
	if Q.empty?
		p -1
		exit
	end
	cx,cy=Q.shift
	T.each{|dx,dy|
		nx=cx+dx;ny=cy+dy
		if -210<nx&&nx<210 && -210<ny&&ny<210 && !D[[nx,ny]] && !X[[nx,ny]]
			D[[nx,ny]]=D[[cx,cy]]+1
			Q<<[nx,ny]
			if nx==x && ny==y
				p D[[nx,ny]]
				exit
			end
		end
	}
}
