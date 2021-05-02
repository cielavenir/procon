#!/usr/bin/ruby
N,K=gets.split.map &:to_i
v=$<.map{|e|e.split.map &:to_f}
p (0.0..100).bsearch{|d|v.map{|e|e[0]*(e[1]-d)}.sort[-K..-1].reduce(:+)<0}