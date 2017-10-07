#!/usr/bin/ruby
n,k=gets.split.map &:to_i;a=$<.map{|e|e.split.map &:to_i};q=0
p (0..31).map{|i|
	l=k>>i<<i|q;q+=1<<i-1;i>0&&k[i-1]<1?0:a.select{|x,y|x|l==l}.map(&:last).reduce(0,:+)
}.max
