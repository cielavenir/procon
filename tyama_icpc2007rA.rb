#!/usr/bin/ruby
loop{
	n,k,m=gets.split.map &:to_i
	break if n==0
	r=0
	1.step(n-1){|i|r=(r+k)%i}
	p (r+m)%n+1
}