#!/usr/bin/ruby
I=->{gets.split.map &:to_i}
N,Q=I[]
A=1,c=1,1,*[0]*(N-2),1
Q.times{
	a,b=I[]
	A[a],A[b]=A[b],A[a]
	c=c==a ?b:c==b ?a:c
	#c!=a&&c!=b||c=a+b-c
	A[c-1]=A[c+1]=1
}
p A.reduce(:+)-2
