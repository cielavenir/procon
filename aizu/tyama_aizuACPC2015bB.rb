#!/usr/bin/ruby
#coding:utf-8
gets
A,D=gets.split.map(&:to_i)
#Hashをデフォルトキー付きで持てば、配列初期化を回避できる
h=Hash.new{|h,k|h[k]=(A-D)+D*k}
gets.to_i.times{
	x,y,z=gets.split.map(&:to_i)
	h[y],h[z]=h[z],h[y] if x==0
	h[y]=h[z] if x==1
}
p h[gets.to_i]