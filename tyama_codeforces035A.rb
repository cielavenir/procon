#!/usr/bin/ruby
$stdin=open("input.txt","rb")
$>=open("output.txt","wb")
a=[0]*4
a[gets.to_i]=1
while gets
	x,y=$_.split.map(&:to_i)
	a[x],a[y]=a[y],a[x]
end
p a.index(1)