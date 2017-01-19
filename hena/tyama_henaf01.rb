#!/usr/bin/env ruby
#18:15-18:28
#http://nabetani.sakura.ne.jp/hena/ordf01_twicel/
#http://qiita.com/Nabetani/items/8e02ede04315b4eadd6d

H=W=8
def dfs(a,x,y,c)
	a[y][x]=-1
	r=1
	[[-1,0],[0,-1],[1,0],[0,1]].each{|dx,dy|
		if 0<=x+dx&&x+dx<W && 0<=y+dy&&y+dy<H && a[y+dy][x+dx]==c
			r+=dfs(a,x+dx,y+dy,c)
		end
	}
	r
end
while gets
	a=$_.chomp.split('/').map{|e|('%08b'%e.hex).chars.map(&:to_i)}
	r=[0,0]
	8.times{|i|8.times{|j|
		c=a[j][i]
		r[c]+=1 if c>=0&&dfs(a,i,j,c)==2
	}}
	puts r*','
	STDOUT.flush
end
