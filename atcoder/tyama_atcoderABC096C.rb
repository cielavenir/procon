#!/usr/bin/ruby
h,w=gets.split.map &:to_i
m=h.times.map{gets.chomp}
h.times{|y|w.times{|x|
	if m[y][x]=='#'
		d={[y,x]=>0}
		q=[[y,x]]
		while !q.empty?
			c=q.shift
			[[-1,0],[0,-1],[1,0],[0,1]].each{|dy,dx|
				ny=c[0]+dy
				nx=c[1]+dx
				if 0<=ny&&ny<h && 0<=nx&&nx<w && m[ny][nx]=='#' && !d[[ny,nx]]
					d[[ny,nx]]=d[c]+1
					q<<[ny,nx]
				end
			}
		end
		if d.size==1
			puts :No
			exit
		end
		d.each_key{|a,b|m[a][b]='.'}
	end
}}
puts :Yes
