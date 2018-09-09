#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/hena/orde27ligmir/
#https://qiita.com/Nabetani/items/0b2f459ec128c89948f4

#x,y
D={
	'.'=>{
		[0,-1]=>[0,-1],  #N
		[1,0]=>[1,0],   #E
		[0,1]=>[0,1],   #S
		[-1,0]=>[-1,0], #W
	},
	'1'=>{
		[0,-1]=>[1,0],  
		[1,0]=>[0,-1],
		[0,1]=>[-1,0],
		[-1,0]=>[0,1],
	},
	'0'=>{
		[0,-1]=>[-1,0],  
		[1,0]=>[0,1],
		[0,1]=>[1,0],
		[-1,0]=>[0,-1],
	},
}
H=W=5

while gets
	m=$_.chomp.split('/')
	x,y=[0,0]
	H.times{|h|W.times{|w|
		if m[h][w]=='Y'
			x,y=w,h
			m[h][w]='.'
		end
	}}
	r=[]
	dx,dy=[0,-1]
	visited={[x,y,dx,dy]=>1}
	while 0<=x&&x<W && 0<=y&&y<H && m[y][x]!='x'
		r<<[x,y]
		dx,dy=D[m[y][x]][[dx,dy]]
		x+=dx
		y+=dy
		k=[x,y,dx,dy]
		break if visited[k]
		visited[k]=1
	end
	puts r.map{|x,y|(x+y*W+97).chr}.uniq.sort*''
	STDOUT.flush
end
