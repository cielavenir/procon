#!/usr/bin/ruby
require 'prime'
N,K=gets.split.map(&:to_i)
A=N.prime_division.map{|n,p|(0..p).map{|i|n**i}}
A<<[1] if A.empty?
B=A.shift.product(*A).map{|e|e.reduce(:*)}.sort
p K>B.size ? -1 : B[K-1]
