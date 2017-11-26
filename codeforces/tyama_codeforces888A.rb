#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
p a.each_cons(3).count{|x,y,z|(x>y&&z>y)||(x<y&&z<y)}
