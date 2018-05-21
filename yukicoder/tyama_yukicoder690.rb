#!/usr/bin/ruby
k=gets.to_i
r=[]
(2..31).map{|a|(1...a).map{|b|r<<b<<a};k[a-2]>0&&r<<a<<32}
p 32,r.size/2,*r
