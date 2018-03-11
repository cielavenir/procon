#!/usr/bin/env ruby
#https://qiita.com/Nabetani/items/dae474bc17827f9b1537
#http://nabetani.sakura.ne.jp/hena/ordf10updown/

# k2pc-Cと同じ問題かと思ったらあっちは四角数じゃなくて三角数だった。。

def decode(x,y)
	return nil if x<0||y<0
	return 0 if x==0&&y==0
	k=[x-1,y-1].max+1
	if k%2==0
		if x>=y
			#y==n-k*k
			y+k*k
		else
			#x==k*2-n+k*k
			-x+k*2+k*k
		end
	else
		if x<=y
			x+k*k
		else
			-y+k*2+k*k
		end
	end
end
def encode(n)
	k=Math.sqrt(n).to_i
	r=n-k*k
	if k%2==0
		if r<=k
			[k,r]
		else
			[k*2-r,k]
		end
	else
		if r<=k
			[r,k]
		else
			[k,k*2-r]
		end
	end
end

while gets
	x,y=encode($_.to_i-1)
	puts [[0,-1],[0,1],[-1,0],[1,0]].map{|dx,dy|
		n=decode(x+dx,y+dy)
		n ? n+1 : '-'
	}*','
	STDOUT.flush
end
