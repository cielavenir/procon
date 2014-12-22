#!/usr/bin/ruby
a=[
	nil,
	nil,
	nil,
	[0,1],
	nil,
	[1,0],
	[0,2],
	nil,
	[1,1],
	[0,3],
	[2,0],
	[1,2],
	[0,4],
]
13.step(100000){|i|
	a[i]=a[i-5].dup
	a[i][0]+=1
	if a[i][0]==3
		a[i][1]+=5
		a[i][0]=0
	end
}
gets.to_i.times{
	n=gets.to_i
	puts a[n] ? '5'*3*a[n][1]+'3'*5*a[n][0] : -1
}