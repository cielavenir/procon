#!/usr/bin/ruby
h,w=gets.split.map(&:to_i)
sy,sx,gy,gx=gets.split.map{|e|e.to_i-1}
m=h.times.map{gets.chomp.chars.map(&:to_i)}
d={[sx,sy]=>0}
q=[[sx,sy]]
while !q.empty?
	x,y=q.shift
	[[-1,0],[0,-1],[1,0],[0,1]].each{|x0,y0|
		if 0<=x+x0&&x+x0<w && 0<=y+y0&&y+y0<h && (m[y][x]-m[y+y0][x+x0]).abs<=1 && !d[[x+x0,y+y0]]
			d[[x+x0,y+y0]]=d[[x,y]]+1
			q<<[x+x0,y+y0]
		end
		if 0<=x+x0*2&&x+x0*2<w && 0<=y+y0*2&&y+y0*2<h && m[y][x]>m[y+y0][x+x0] && m[y][x]==m[y+y0*2][x+x0*2] && !d[[x+x0*2,y+y0*2]]
			d[[x+x0*2,y+y0*2]]=d[[x,y]]+1
			q<<[x+x0*2,y+y0*2]
		end
	}
end
puts d[[gx,gy]] ? :YES : :NO
