#!/usr/bin/ruby
t={
	3=>lambda{|n|n*(n+1)/2},
	5=>lambda{|n|n*(3*n-1)/2},
	6=>lambda{|n|n*(2*n-1)},
}
N,a,b=gets.split.map(&:to_i)
a=t[a]
b=t[b]
n=1
m=1
while a[n]<N
	n+=1 while a[n]<b[m]
	m+=1 while a[n]>b[m]
	if a[n]==b[m]
		p a[n]
		m+=1
	end
end