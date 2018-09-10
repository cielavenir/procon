#!/usr/bin/env crystal
n=gets.not_nil!.to_i
m=3*n+1
t=[true]*m
t[0]=t[1]=false
(2...m).each{|i|t[i]&&(i*2).step(to: m-1,by: i){|j|t[j]=false}}
q=(2...m).select{|i|t[i]}
o=q.dup
r=0_i64
a=[0]*m
q.each{|c|
	c>n&&break
	o.each{|s|r+=a[s-c]};o.shift
	q.each{|x|x>=c&&break;a[x+c]+=1}
}
puts r
