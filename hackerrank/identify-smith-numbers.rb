#!/usr/bin/ruby
require 'prime'
def f(n) n.to_s.chars.map(&:to_i).reduce(:+) end
n=gets.to_i
p f(n)==n.prime_division.map{|n,p|f(n)*p}.reduce(:+) ? 1 : 0