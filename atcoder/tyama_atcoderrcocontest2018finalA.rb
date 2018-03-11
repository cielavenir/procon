#!/usr/bin/ruby

# とりあえず妖精の位置を考慮せずに壁を作ることが第一段階だったっぽい

def l(n,_N)
	upperRight=n<_N ? [n,0] : [_N-1,n-_N]
	a=[]
	while upperRight[0]>=0 && upperRight[1]<_N
		a<<upperRight.dup
		upperRight[0]-=1
		upperRight[1]+=1
	end
	a
end

N,k=gets.split.map &:to_i
n=N
d=i=0
sgn=1
loop{
	break if n<0||2*N<=n
	a=l(n,N)
	a=a.reverse if i%4==0||i%4==3
	a=a[0...-1]
	a.each{|e|
		puts '%d %d'%e
		k-=1
		exit if k==0
	}
	d+=i==1 ? 4 : 3
	n=n+d*sgn
	sgn*=-1
	i+=1
}
k.times{puts '-1 -1'}
