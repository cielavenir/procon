#!/usr/bin/ruby
a,b,c,d,e=gets.split.map(&:to_i)
b-=7*c
if b<0 then a+=8*b;b=0 end
if b%8>0 then a-=8*(8-b%8);b+=8-b%8 end
b/=8
a-=61*d+42*c+61*b
if a<0 then a=0 end
p e+d+c+b+(a+124)/125