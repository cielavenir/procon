#!/usr/bin/ruby
T=[1000,100,25,1]
s=0
$<.each_line.with_index(1).map{|e,i|s+=e.to_i*T[i]}
r=0
1.step(T.size-1){|i|r+=s%T[i-1]/T[i]}
p r