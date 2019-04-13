#!/usr/bin/ruby
n,x,y=$<.map &:to_f
p x<1?(a=x;(2..n).map{a=x+y*y*a/(1-x*a)};a):1
