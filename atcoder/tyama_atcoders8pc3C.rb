#!/usr/bin/ruby
M=10**9+7
n,k,*a=`dd`.split.map(&:to_i)
m=(n+1).times.map{[0]*256}
m[0][r=0]=q=1
n.times{|i|(i+1).downto(1){|l|256.times{|j|
	m[l][j]+=m[l-1][a[i]^j]
}}}
1.upto(n){|l|r+=m[l][k]*q=q*l%M}
p r%M
