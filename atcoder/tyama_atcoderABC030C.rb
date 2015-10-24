#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
x,y=gets.split.map(&:to_i)
a=gets.split.map(&:to_i)
b=gets.split.map(&:to_i)

ca=0
cb=0
c=0
r=0
loop{
	ca+=1 while a[ca]&&a[ca]<c
	break if !a[ca]
	c=a[ca]+x
	cb+=1 while b[cb]&&b[cb]<c
	break if !b[cb]
	c=b[cb]+y
	r+=1
}
p r