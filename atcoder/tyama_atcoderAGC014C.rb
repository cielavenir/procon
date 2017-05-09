#!/usr/bin/ruby
def z(h,w)
	[h,w,H-1-h,W-1-w].min
end
D=[[-1,0],[0,-1],[1,0],[0,1]]
H,W,K=gets.split.map(&:to_i)
i=j=nil
m=[]
$<.each_with_index{|l,_|
	l.chomp!
	z=W.times.find{|w|l[w]==?S}
	if z
		i=_
		j=z
	end
	m<<l.chars
}
r=z(i,j)
q=[[i,j]]
m[i][j]=0
while !q.empty?
	h,w=q.shift
	next if m[h][w]+1>K
	D.each{|dy,dx|
		y=h+dy
		x=w+dx
		if 0<=y&&y<H && 0<=x&&x<W && m[y][x]==?.
			m[y][x]=m[h][w]+1
			r=[r,z(y,x)].min
			q<<[y,x]
		end
	}
end
p (r+K-1)/K+1
