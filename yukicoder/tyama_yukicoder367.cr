#!/usr/bin/env crystal
D=[[{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}],[{-1,-1},{-1,1},{1,-1},{1,1}]]
h,w=gets.not_nil!.split.map(&.to_i)
q=[] of Tuple(Int32,Int32,Int32)
g=Tuple(Int32,Int32)
m=[] of String
h.times{|y|s=gets.not_nil!.chomp;s.size.times{|x|s[x]=='S'&&q<<{0,x,y};s[x]=='G'&&(g={x,y})};m<<s}
d={q[0]=>0}
while !q.empty?
	ck=q.shift
	c,cx,cy=ck
	D[c].each{|(dx,dy)|
		nx,ny=cx+dx,cy+dy
		if 0<=nx&&nx<w && 0<=ny&&ny<h
			nc=c^(m[ny][nx]=='R'?1:0)
			z={nc,nx,ny}
			if !d.has_key?(z)
				d[z]=d[ck]+1
				q<<z
				if {nx,ny}==g
					p d[z];exit
				end
			end
		end
	}
end
p -1
