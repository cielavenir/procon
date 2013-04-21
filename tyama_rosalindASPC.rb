#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a=[1,1]
2.step(n){
	b=[1]
	1.step(a.size-1){|j|b<<a[j-1]+a[j]}
	b<<1
	a=b
}
p a[m..n].reduce(:+)%10**6