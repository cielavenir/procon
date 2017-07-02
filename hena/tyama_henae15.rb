#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde15nohil/
#http://qiita.com/Nabetani/items/705fa83cfbf20377b92f

def num2place(n)
	x=y=0
	z=1
	while n>0
		if n%3==1
			x+=z
		elsif n%3==2
			y+=z
		end
		n/=3
		z*=2
	end
	[x,y]
end

def place2num(x,y)
	return nil if x<0 || y<0 || x&y>0 # x|y!=x+y
	n=0
	z=1
	while x>0||y>0
		if x%2>0
			n+=z
		elsif y%2>0
			n+=2*z
		end
		x/=2
		y/=2
		z*=3
	end
	n
end

while gets
	x,y=num2place($_.to_i)
	puts [[0,-1],[-1,0],[1,0],[0,1]].map{|dx,dy| # this order is important
		place2num(x+dx,y+dy)
	}.compact*','
	STDOUT.flush
end
