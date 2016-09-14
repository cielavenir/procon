#!/usr/bin/env crystal
Z=[0,-1,0,1,0];M=1000000007
def f(x,y,h,w,k,m)
	ky=x*h+y
	if k[ky]==0
		r=1
		4.times{|i|
			nx=x+Z[i]
			ny=y+Z[i+1]
			0<=nx&&nx<w && 0<=ny&&ny<h && m[y][x]<m[ny][nx] && (r=(r+f(nx,ny,h,w,k,m))%M)
		}
		k[ky]=r
	end
	k[ky]
end
h,w=gets.not_nil!.split.map &.to_i
m=h.times.map{gets.not_nil!.split.map &.to_i}.to_a
k=[0]*(h*w)
r=0
h.times{|y|w.times{|x|r=(r+f(x,y,h,w,k,m))%M}}
p r
