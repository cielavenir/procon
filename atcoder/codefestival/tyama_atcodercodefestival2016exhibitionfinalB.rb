#!/usr/bin/ruby
a,b,c,d,e,f=`dd`.split.map(&:to_f)
x,y,z,w=c-a,d-b,e-a,f-b
s=(x*w-y*z).abs/2
o,q,r=[[x,y],[z,w],[x-z,y-w]].map{|x,y|(x*x+y*y)**0.5}.sort
p 2*s/(o+q+r+4*s/r)
