#!/usr/bin/ruby
STDOUT.sync=true
def chk(*a)
	puts '? %d %d %d %d'%a
	gets.to_i
end
n=gets.to_i
a=[1,2].map{|z|-(-n..-1).bsearch{|i|chk(-i,1,n,n)>=z}}
b=[1,2].map{|z|-(-n..-1).bsearch{|i|chk(1,-i,n,n)>=z}}
c=[1,2].map{|z|(1..n).bsearch{|i|chk(1,1,i,n)>=z}}
d=[1,2].map{|z|(1..n).bsearch{|i|chk(1,1,n,i)>=z}}
16.times{|i|
	x11,y11,x12,y12=a[i[0]],b[i[1]],c[i[2]],d[i[3]]
	x21,y21,x22,y22=a[i[0]^1],b[i[1]^1],c[i[2]^1],d[i[3]^1]
	if x11<=x12&&y11<=y12 && x21<=x22&&y21<=y22 && chk(x11,y11,x12,y12)==1 && chk(x21,y21,x22,y22)==1
		puts '! %d %d %d %d %d %d %d %d'%[x11,y11,x12,y12,x21,y21,x22,y22]
		break
	end
}