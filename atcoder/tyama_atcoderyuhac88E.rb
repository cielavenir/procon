#!/usr/bin/ruby
#coding:utf-8
Encoding.default_external='UTF-8'
A=gets.to_i.times.map{gets.chomp}
I=$<.map(&:chomp)
T=[
	[I[0][2],I[1][2]=="↓"?0:1],
	[I[2][0],I[2][1]=="→"?0:1],
	[I[2][4],I[2][3]=="→"?1:0],
	[I[4][2],I[3][2]=="↓"?1:0],
]
puts T.map{|c,x|A.select{|e|e[x]==c}.map{|e|e[x^1]}}.reduce{|s,e|s&e}