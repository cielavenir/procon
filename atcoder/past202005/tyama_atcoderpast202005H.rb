#!/usr/bin/ruby
n,l=gets.split.map &:to_i
x=Hash.new 0
gets.split.each{|e|x[e.to_i]=1}
t1,t2,t3=gets.split.map &:to_i
z=[0]+[10**9]*(l+10)
r=10**9
(0...l).each{|i|
	z[i+1] = [z[i+1],z[i]+t1+t3*x[i+1]].min
	z[i+2] = [z[i+2],z[i]+t1+t2+t3*x[i+2]].min
	z[i+4] = [z[i+4],z[i]+t1+t2*3+t3*x[i+4]].min
	if i+4>l
		r=[r,z[i]+t1/2+t2/2+t2*(l-i-1)].min
	end
}
p [r,z[l]].min
