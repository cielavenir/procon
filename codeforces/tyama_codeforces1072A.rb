#!/usr/bin/ruby
w,h,k=gets.split.map &:to_i
p k*(2*(w+h)-8*k+4)
