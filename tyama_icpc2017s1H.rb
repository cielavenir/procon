#!/usr/bin/ruby
y,x=gets.split.map(&:to_i).sort;p x<0?-2*x-2*y-3:x>0?x==y ?x*2:4*x-2*y-3:-2*y
