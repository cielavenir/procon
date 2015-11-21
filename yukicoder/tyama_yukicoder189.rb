#!/usr/bin/ruby
A=gets.split.map{|e|
	a=[]
	s=0
	e.bytes{|b|
		n=b-48
		asiz=a.size
		a+=[0]*([9+asiz,n+s].max-asiz)
		(asiz-1).downto(0){|j|9.downto(1){|i|a[j+i]+=a[j]}}
		(0...n).each{|j|a[j+s]+=1}
		s+=n
	}
	a[s]+=1
	a
}
r=0
(1...[A[0].size,A[1].size].min).each{|i|r=(r+A[0][i]*A[1][i])%1000000009}
p r