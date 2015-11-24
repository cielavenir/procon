#!/usr/bin/ruby
M={}
def d(n)
	M[n]||=lambda{
		r=2--~n/n # r=n==1?0:1
		i=2
		(n%i==0&&r=[r,d(i),d(n/i)].max;i+=1)while i*i<=n
		(r+=n%10;n/=10)while n>0
		r
	}[]
end
puts $<.map{|e|d(e.to_i)}