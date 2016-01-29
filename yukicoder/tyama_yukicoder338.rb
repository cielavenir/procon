#!/usr/bin/ruby
def diveqround(d,n,r) (r*10-5)*n<=d*10 && d*10<(r*10+5)*n end
A,B=gets.split.map(&:to_i)
r=200
(0..100).each{|a|(0..100).each{|b|
	r=[r,a+b].min if diveqround(100*a,a+b,A)&&diveqround(100*b,a+b,B)
}}
p r