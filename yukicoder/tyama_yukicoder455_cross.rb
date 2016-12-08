#!/usr/bin/ruby
H,W,*M=`dd`.split
a=[]
H.to_i.times{|h|W.to_i.times{|w|M[h][w]==?*&&a<<[h,w]}}
a,b=*a
h,w=[[0,0],[1,0],[0,1]].find{|h,w|(a[0]-h)*(b[1]-w)!=(b[0]-h)*(a[1]-w)}
M[h][w]=?*
puts M
