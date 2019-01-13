#!/usr/bin/ruby
n,m=gets.split.map &:to_i
a,b=$<.map{|e|e.split.map(&:to_i).sort.reverse<<0}
x=y=0
c=1
(n*m).downto(1){|i|
	if a[x]==i&&b[y]==i
		x+=1;y+=1
	elsif a[x]==i
		x+=1;c*=y
	elsif b[y]==i
		y+=1;c*=x
	else
		c*=x*y-n*m+i
	end
	c%=10**9+7
}
p c
