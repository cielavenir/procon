#!/usr/bin/ruby
N,*A=`dd`.split.map &:to_i
x,y=[A,A.reverse].map{|_|
	t=[];r=[c=0]
	_.each_with_index{|a,i|
		b=a;q=1;(x,d,n=t.pop;k=Math.log(b.to_f/x,4).ceil*2;b=d<<k;c+=n*k;q+=n)while !t.empty?&&t[-1][0]<b;t<<(t.empty? ? [a,0,q]:[a,b,q]);r<<c
	}
	r
}
p (0..N).map{|i|x[i]+i+y[-1-i]}.min
