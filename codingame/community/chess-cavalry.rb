#!/usr/bin/ruby
D=[[-2,-1],[-2,1],[-1,-2],[-1,2],[1,-2],[1,2],[2,-1],[2,1]]
W,H=gets.split.map(&:to_i)
M=$<.each_with_index.map{|e,i|
	B=[i,e.index('B')] if e.index('B')
	E=[i,e.index('E')] if e.index('E')
	e.chomp
}
depth={B=>0}
q=[B]
while !q.empty?
	cur=q.shift
	y,x=cur
	D.each{|y0,x0|
		if 0<=x0+x&&x0+x<W && 0<=y0+y&&y0+y<H && M[y0+y][x0+x]!='#'
			key=[y0+y,x0+x]
			if !depth.has_key?(key)
				depth[key]=depth[cur]+1
				q<<key
				if key==E
					p depth[key]
					exit
				end
			end
		end
	}
end
puts :Impossible