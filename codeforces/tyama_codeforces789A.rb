#!/usr/bin/ruby
n,k,*a=$<.read.split.map(&:to_i)
p (a.map{|e|(e+k-1)/k}.reduce(:+)+1)/2
