#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
h={}
a=m.times.map{gets.split.map(&:to_i)}
a.each{|x,y|h[[x,y]]=1}
r=0
(1..n).each{|i|(1..n).each{|j|
	r+=(1..n).count{|k|h.has_key?([i,k])&&h.has_key?([k,j])}**2
}}
p r
