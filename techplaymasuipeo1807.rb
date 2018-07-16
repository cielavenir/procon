#!/usr/bin/ruby
r=0
n=gets.to_i
k=(n..n+8).reduce(:+)/3
[*n..n+8].permutation{|a|
	if
		a[0]+a[1]+a[2]==k &&
		a[3]+a[4]+a[5]==k &&
		a[6]+a[7]+a[8]==k &&
		a[0]+a[3]+a[6]==k &&
		a[1]+a[4]+a[7]==k &&
		a[2]+a[5]+a[8]==k &&
		a[0]+a[4]+a[8]==k &&
		a[2]+a[4]+a[6]==k
	then
		p a
		r+=1
	end
}
#p r
