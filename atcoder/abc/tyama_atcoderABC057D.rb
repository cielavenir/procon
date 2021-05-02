#!/usr/bin/ruby
M=10**24+7 # selected with miller_rabin
n,a,b,*v=`dd`.split.map &:to_i
I=[1,1];*F=I;*R=I
2.upto(n){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
v.sort_by! &:-@
(a-1).downto(x=y=0){|i|
	break if v[i]!=v[a-1]
	x+=1
	y+=1
}
a.upto(n-1){|i|
	break if v[i]!=v[a-1]
	x+=1
}

p v[0,a].reduce(:+)*1.0/a
p (y==a ? a..[x,b].min : y..y).reduce(0){|s,i|s+F[x]*R[i]*R[x-i]%M}
