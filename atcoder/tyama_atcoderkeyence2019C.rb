#!/usr/bin/ruby
n=gets.to_i
y=$<.map{|e|e.split.map &:to_i}.transpose.map{|x,y|x-y}.sort
x=y.dup
l=0
r=n-1
while l<r && x[l]<0
	r-=1 if x[r]==0
	x[l]+=z=[x[r],-x[l]].min
	x[r]-=z
	l+=1 if x[l]==0
end
p x[l]<0 ? -1 : (0...n).count{|i|x[i]!=y[i]}
