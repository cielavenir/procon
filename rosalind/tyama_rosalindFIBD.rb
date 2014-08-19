#!/usr/bin/ruby
N,k=gets.split.map(&:to_i)
k-=1
a=Array.new(N){|a|a=[]*k}
a[0][0]=1;
s=0
1.step(N-1){|j|
	a[j][0]=s
	s=0
	k.downto(1){|i|
		s+=a[j][i]=a[j-1][i-1]||0
	}
}
#p a
p a.last.reduce(:+)