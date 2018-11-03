#!/usr/bin/ruby
#http://nabetani.sakura.ne.jp/hena/orde28sqst/
#https://qiita.com/Nabetani/items/4e3fac2746ca05a93165

while gets
	seq,n=$_.split('/')
	nx=ny=Rational(1)
	mx=my=Rational(0)
	a=[[[0,0],[1,1]]]
	seq.chars.each_slice(2){|c,k|
		width=nx-mx
		height=ny-my
		k=k.to_i
		if c==?N
			siz=width/k
			k.times{|i|
				a<<[[mx+siz*i,ny],[mx+siz*(i+1),ny+siz]]
			}
			ny+=siz
		elsif c==?E
			siz=height/k
			k.times{|i|
				a<<[[nx,ny-siz*(i+1)],[nx+siz,ny-siz*i]]
			}
			nx+=siz
		elsif c==?S
			siz=width/k
			k.times{|i|
				a<<[[mx+siz*i,my-siz],[mx+siz*(i+1),my]]
			}
			my-=siz
		elsif c==?W
			siz=height/k
			k.times{|i|
				a<<[[mx-siz,ny-siz*(i+1)],[mx,ny-siz*i]]
			}
			mx-=siz
		end
	}
	q=a[n.to_i-1]
	puts (1..a.size).select{|i|
		(a[i-1][0][0]==q[1][0]||a[i-1][1][0]==q[0][0])&&a[i-1][0][1]<q[1][1]&&q[0][1]<a[i-1][1][1] or
		(a[i-1][0][1]==q[1][1]||a[i-1][1][1]==q[0][1])&&a[i-1][0][0]<q[1][0]&&q[0][0]<a[i-1][1][0]
	}*','
	STDOUT.flush
end
