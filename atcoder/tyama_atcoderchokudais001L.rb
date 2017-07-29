#!/usr/bin/ruby
eval'N,*A='+`dd`.split*?,;A.map!{|e|e-1}
r=0;N.times{|i|(A[A[i]],A[i]=A[i],A[A[i]];r+=1)while A[i]!=i}
puts [:YES,:NO][N-r&1]
