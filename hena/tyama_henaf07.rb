#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/ordf07walk/
#https://qiita.com/Nabetani/items/cf93b63acc8a313c88bb
STDOUT.sync=true

while gets
	a=$_.chomp.split('/').map{|e|e.chars.map(&:to_i)}
	q=[[2,0]]
	z={q[0]=>0}
	while !q.empty?
		cx,cy=q.shift
		[[-1,0],[0,-1],[1,0],[0,1]].each{|dx,dy|
			nx,ny=cx+dx,cy+dy
			if 0<=nx&&nx<a[0].size && 0<=ny&&ny<a.size && !z[[nx,ny]] && (a[cy][cx]-a[ny][nx]).abs<=1
				z[[nx,ny]]=z[[cx,cy]]+1
				q<<[nx,ny]
			end
		}
		a[cy][cx]='*'
	end
	puts a.map(&:join)*'/'
end
