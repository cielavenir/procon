#!/usr/bin/ruby
A,B,X,Y=gets.split.map(&:to_f)
p (A+B)*[X/A,Y/B].min