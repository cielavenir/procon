#!/usr/bin/ruby
Z=[0,-1,0,1,0]
MOD=10**9+7
def dfs(x,y)
	ky=x*H+y
	$memo[ky]||=lambda{
		r=1
		4.times{|i|
			nx=x+Z[i]
			ny=y+Z[i+1]
			if 0<=nx&&nx<W && 0<=ny&&ny<H && M[y][x]<M[ny][nx]
				r=(r+dfs(nx,ny))%MOD
			end
		}
		r
	}.call
end
H,W=gets.split.map(&:to_i)
M=H.times.map{gets.split.map(&:to_i)}
$memo=[nil]*(H*W)
r=0
H.times{|y|W.times{|x|
	r=(r+dfs((x+W/2)%W,(y+H/2)%H))%MOD
}}
p r