#!/usr/bin/ruby
n,k,x,y=$<.map &:to_i;p n<k ? x*n : x*k+y*(n-k)