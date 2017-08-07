#!/usr/bin/ruby
N,*A=`dd`.split.map &:to_i
h=[0]*3
A.map{|e|h[(0..2).find{|i|e%2**(2-i)<1}]+=1}
puts h[2]-(h[1]>0?0:1)>h[0]?:No: :Yes
