#!/usr/bin/ruby
N=gets.to_i
A=[]
h={}
gets.split.each_with_index{|e,i|
	n=e.to_i-1
	if !A[n]&&n<N
		A[n]=i
		h[i]=n
	end
}
x=0
N.times{|i|
	if !A[i]
		x+=1 while h[x]
		A[i]=x
		h[x]=i
	end
}
B=[]
A.each_with_index{|e,i|B[e]=i+1}
puts B*' '