#!/usr/bin/ruby
H,W=gets.split.map &:to_i
m=H.times.map{gets.chomp}
r=0;m.each{|e|r+=e.count('.')}
d={[0,0]=>1}
q=[[0,0]]
while !q.empty?
	cy,cx=q.shift
	[[-1,0],[0,-1],[1,0],[0,1]].each{|dy,dx|
		ny=cy+dy
		nx=cx+dx
		if 0<=ny&&ny<H && 0<=nx&&nx<W && m[cy][cx]=='.' && !d[[ny,nx]]
			d[[ny,nx]]=d[[cy,cx]]+1
			q<<[ny,nx]
		end
	}
end
p d.has_key?([H-1,W-1]) ? r-d[[H-1,W-1]] : -1
