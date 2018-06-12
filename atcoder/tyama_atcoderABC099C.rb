#!/usr/bin/ruby
T=[1,6,9,36,81,216,729,1296,6561,7776,46656,59049]
N=gets.to_i
A=[0,1]
(2..N).each{|i|A<<T.select{|e|e<=i}.map{|e|A[i-e]+1}.min}
p A[N]
