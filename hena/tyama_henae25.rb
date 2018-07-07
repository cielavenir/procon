#!/usr/bin/env ruby
#https://mtsmfm.github.io/2018/07/07/doukaku-e25.html
#https://qiita.com/mtsmfm/items/9e06456b4330305d4ed0

def build(x,y,dx,dy)
	[[x,y],[x+dx,y+dy],[x+dx-dy,y+dy+dx],[x-dx-dy,y-dy+dx]]
end
def format(a)
	a[1..-1].map{|x,y|'(%d,%d)'%[x,y]}*','
end
def ok(h,w,x,y,dx,dy)
	build(x,y,dx,dy).all?{|nx,ny|
		0<=nx&&nx<w && 0<=ny&&ny<h
	}
end

STDOUT.sync=true
while gets
	qx=qy=0;c=Float::INFINITY
	w,h,x,y=$_.scan(/\d+/).map &:to_i
	(-x..w-x).each{|dx|(-y..h-y).each{|dy|
		next if dx==0&&dy==0
		if ok(h,w,x,y,dx,dy)
			if dx**2+dy**2>qx**2+qy**2
				c=0
				qx=dx;qy=dy
			end
			c+=1 if dx**2+dy**2==qx**2+qy**2
		end
	}}
	puts c>1 ? '-' : format(build(x,y,qx,qy))
end
