#!/usr/bin/ruby
N,*A_=`dd`.split.map &:to_i
A=0,*A_,0
S=A.each_cons(2).reduce(0){|s,(x,y)|s+(y-x).abs}
(1..N).map{|i|
	a=A[i]-A[i-1];b=A[i+1]-A[i]
	if a*b>0
		p S
	else
		p S-[a.abs,b.abs].min*2
	end
}
