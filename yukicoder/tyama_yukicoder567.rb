#!/usr/bin/ruby
N=gets.to_i
(p 1;exit)if N>99
m=[1.0,*[0]*6]
N.times{|i|m=[0]+6.times.map{|j|m[j]*(6-j)/6+m[j+1]*-~j/6}}
p m[6]
