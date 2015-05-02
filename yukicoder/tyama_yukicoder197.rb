#!/usr/bin/ruby
A=gets.chomp
N=gets.to_i
B=gets.chomp
puts (A.count('o')!=B.count('o')?true:N>1?false:N<1?A!=B : B!=A[1]+A[0]+A[2]&&B!=A[0]+A[2]+A[1])?:SUCCESS : :FAILURE