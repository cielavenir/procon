#!/usr/bin/ruby
D=[[-1,0],[0,-1],[1,0],[0,1]]
H,W,N,*A=`dd`.split.map &:to_i
M=H.times.map{[nil]*W}
x=0
y=-1
d=2
A.each.with_index(1){|e,i|e.times{
	4.times{|dd|
		nd=(d+dd)%4
		dy,dx=D[nd]
		ny=y+dy
		nx=x+dx
		if 0<=ny&&ny<H && 0<=nx&&nx<W && !M[ny][nx]
			M[ny][nx]=i
			d=nd
			y=ny
			x=nx
			break
		end
	}
}}
puts M.map{|e|e*' '}
