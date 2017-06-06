#!/usr/bin/ruby
f=->k,d,q{
	x=(-d)%10
	d-=10**(k-1)*x-x
	k>1?(10-x-q)*f[k-2,d.abs/10,0]:d==0?10**k :0
}
n=gets.to_i;r=0;1.upto(100){|i|r+=f[i,n,1]};p r
