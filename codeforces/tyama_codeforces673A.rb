#!/usr/bin/ruby
gets;a=[0]+gets.split.map(&:to_i)
z=a.each_cons(2).find{|x,y|y-x>15}
z=(z ? z[0] : a.last)+15
p z>90 ? 90 : z