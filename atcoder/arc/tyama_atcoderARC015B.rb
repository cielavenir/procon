#!/usr/bin/ruby
a=[0,0,0,0,0,0]
gets.to_i.times{
	m,n=gets.split.map(&:to_f)
	a[0]+=1 if 35<=m
	a[1]+=1 if 30<=m && m<35
	a[2]+=1 if 25<=m && m<30
	a[3]+=1 if 25<=n
	a[4]+=1 if n<0 && 0<=m
	a[5]+=1 if m<0
}
puts a*' '