#!/usr/bin/ruby
def popcnt(n)
	r=0
	while n>0
		r+=n%2
		n/=2
	end
	r
end

def lightsout(x,y)
	a=(x*y).times.map{[0,0]}

	#create problem
	x.times{|i|
		y.times{|j|
			a[i+j*x][0]=1<<(i+j*x)
			a[i+j*x][1]= 0 +
				(1<<(i+j*x)) |
				(i>0   ? 1<<(i-1+j*x) : 0) |
				(i<x-1 ? 1<<(i+1+j*x) : 0) |
				(j>0   ? 1<<(i+(j-1)*x) : 0) |
				(j<y-1 ? 1<<(i+(j+1)*x) : 0) |
				(i>0   && j>0   ? 1<<(i-1+(j-1)*x) : 0) |
				(i<x-1 && j>0   ? 1<<(i+1+(j-1)*x) : 0) |
				(i>0   && j<y-1 ? 1<<(i-1+(j+1)*x) : 0) |
				(i<x-1 && j<y-1 ? 1<<(i+1+(j+1)*x) : 0) |
				0;
		}
	}

	#solve
	badbits=0
	(x*y).times{|i|
		if (a[i][1]&(1<<i))==0
			if (i+1...x*y).each{|j|
				if (a[j][1]&(1<<i))!=0
					a[i],a[j]=a[j],a[i]
					break
				end
			} then
				badbits|=1<<i
				next
			end
		end

		(x*y).times{|j|
			next if i==j
			if (a[j][1]&(1<<i))!=0
				a[j][0]^=a[i][0]
				a[j][1]^=a[i][1]
			end
		}
	}
	k=x*y-popcnt(badbits)
	STDERR.puts "quiet pattern=%d"%[x*y-k]

	#0解(quiet pattern)の集合tを用意する
	tmsk=0
	t=[]
	a_ok=[]
	(x*y).times{|i|
		if ((badbits>>i)&1)>0
			t<<a[i][0]
		else
			a_ok<<[i,a[i][0]]
			tmsk|=1<<i
		end
	}

	#入力・解の存在判定
	input=0
	y.times{|j|
		a=gets.split.map(&:to_i)
		x.times{|i|
			input|=a[i]<<j*x+i
		}
	}
	if t.any?{|e|popcnt(e&input)%2>0}
		return -1
	end

	tlst=[0]*(1<<(x*y-k))
	(1<<(x*y-k)).times{|l|
		r=0
		(x*y-k).times{|j|
			if (l&(1<<j))>0
				r^=t[j]
			end
		}
		tlst[l]=r
	}

	r0=1<<29
	c0=0
	a_ok.each{|j|
		if (input&(1<<j[0]))>0
			c0^=j[1]
		end
	}
	#0解の重ね合わせをすべて試す
	(1<<(x*y-k)).times{|l|
		r1=c0
		r1^=tlst[l]
		r0=[r0,popcnt(r1)].min
	}
	r0
end

while gets
	m,n=$_.split.map(&:to_i)
	r=lightsout(n,m)
	puts r<0 ? :Impossible : r
end
