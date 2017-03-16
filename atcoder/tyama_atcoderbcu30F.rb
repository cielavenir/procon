#!/usr/bin/ruby
M=10**9+7;n,a,*z=`dd`.split.map &:to_i
b=0;c=1
z.map{|e|a,b,c=(a+c)*e%M,(b*2+a)%M,c*2%M}
p (a+b)%M
