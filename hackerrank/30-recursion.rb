#!/usr/bin/ruby
def factorial(n) n<2 ? 1 : n*factorial(n-1) end
p factorial(gets.to_i)