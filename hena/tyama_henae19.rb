#!/usr/bin/env ruby
#https://mtsmfm.github.io/2017/11/04/doukaku-e19.html
#http://qiita.com/mtsmfm/items/67bf5c121ecbd9b5fab3

T={'o'=>:odd?,'x'=>:even?}

def enum(a,d,s,n)
	(yield [s];return) if d==n-1
	s0=s
	if a[d]==a[d+1]
		s+=1
		s+=2 if s%2==0
		enum(a,d+1,s,n){|e|yield [s0]+e} if s<2*n
		((s+4)/2*2).step(2*n-1,4){|i|
			enum(a,d+1,i,n){|e|yield [s0]+e}
		}
	else
		s=s/2*2+2
		s.step(2*n-1,4){|i|
			enum(a,d+1,i,n){|e|yield [s0]+e}
		}
	end
end

while gets
	x,y=$_.chomp.split(',')
	n=x.size
	s=x[0]=='o'?0:2
	r=[]
	s.step(2*n-1,4){|i|
		enum(x,0,i,n){|e|
			b=([*0...2*n]-e).map{|z|z/2+1}
			a=e.map{|z|z/2+1}
			if y.chars.zip(b).all?{|_1,_2|_2.send T[_1]}
				r<<[a,b]*','
			end
		}
	}
	puts r*'|'
	STDOUT.flush
end
