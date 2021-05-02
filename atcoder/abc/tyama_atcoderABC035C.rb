#!/usr/bin/ruby
n,q=gets.split.map(&:to_i)
a=[0]*(n+1)
q.times{
	l,r=gets.split.map(&:to_i)
	a[l-1]+=1
	a[r]-=1
}
n.times{|i|a[i+1]+=a[i];putc 48+a[i]%2}
puts