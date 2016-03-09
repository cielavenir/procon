#!/usr/bin/ruby
n,m,*a=$<.read.split.map &:to_i;p [a[0]-1,*a.each_cons(2).map{|x,y|(y-x)/2},n-a[-1]].max