#!/usr/bin/ruby
A=[0]*-~N=gets.to_i
$<.map{|_|n=_.to_i;A[n]=A[n-1]+1}
p N-A.max
