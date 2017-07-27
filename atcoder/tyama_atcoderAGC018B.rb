#!/usr/bin/ruby
N,M=gets.split.map &:to_i;r=N
A=$<.map{|e|h={};e.split.each{|f|h[f.to_i]=1};h}
(M-1).times{
	h=Hash.new 0
	A.map{|e|h[e.first[0]]+=1}
	k,v=h.max_by &:last
	r=[r,v].min
	A.map{|e|e.delete k}
}
p r
