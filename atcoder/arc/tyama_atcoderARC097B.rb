#!/usr/bin/ruby
M=1000;A={1=>1};(2..M).map{|i|k=2;(A[i**k]=1;k+=1)while i**k<=M};p gets.to_i.downto(1).find{|i|A[i]}
