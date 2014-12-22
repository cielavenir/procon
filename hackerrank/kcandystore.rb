#!/usr/bin/ruby
pascal=[[1],[1,1]]
2.step(1000){|i|pascal[i]=[1]+pascal[i-1].each_cons(2).map{|x,y|x+y}+[1]}
gets.to_i.times{
	n=gets.to_i;k=gets.to_i
	p pascal[n+k-1][k]%10**9
}