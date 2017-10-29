#!/usr/bin/ruby
D=[[[-1,-2],[1,-2],[-2,-1],[2,-1],[-2,1],[2,1],[-1,2],[1,2]],[[-1,-1],[-1,1],[1,-1],[1,1]]]
h,w=gets.split.map(&:to_i)
g=q=[]
m=$<.map.with_index{|e,y|s=e.chomp;s.each_char.with_index{|c,x|q<<[0,x,y]if c=='S';g=[x,y]if c=='G'}}
d={q[0]=>0}
while !q.empty?
	c,cx,cy=q.shift
	D[c].each{|dx,dy|
		nx,ny=cx+dx,cy+dy
		if 0<=nx&&nx<w && 0<=ny&&ny<h
			nc=c^(m[ny][nx]=='R'?1:0)
			z=[nc,nx,ny]
			if !d[z]
				d[z]=d[[c,cx,cy]]+1
				q<<z
				if [nx,ny]==g
					p d[z];exit
				end
			end
		end
	}
end
p -1
