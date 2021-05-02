#!/usr/bin/ruby
gets;q=0;p [[0,0],*$<.map{|e|e.split.map &:to_i}].each_cons(2).map{|(z,w),(x,y)|q=[0,q-x+z].max+y}.max
