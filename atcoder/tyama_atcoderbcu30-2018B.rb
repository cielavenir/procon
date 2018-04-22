#!/usr/bin/ruby
H,W=gets.split.map &:to_i
y,x=gets.split.map &:to_i
A=H.times.map{gets.split.map &:to_i}
M=H.times.map{'.'*W}
x-=1
y-=1
M[y][x]='W'
loop{
	ny=nx=nil
	c=A[y][x]
	[[-1,0],[0,-1],[0,1],[1,0]].each{|dx,dy|
		if 0<=y+dy&&y+dy<H && 0<=x+dx&&x+dx<W && A[y+dy][x+dx]<c && M[y+dy][x+dx]=='.'
			c=A[y+dy][x+dx]
			ny=y+dy
			nx=x+dx
		end
	}
	break if !ny
	y=ny
	x=nx
	M[ny][nx]='W'
}
puts M
