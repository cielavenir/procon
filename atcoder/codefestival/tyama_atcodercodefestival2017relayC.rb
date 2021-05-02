#!/usr/bin/ruby
(N,K),*A=$<.map{|e|e.split.map &:to_i}
l=A[0][0]+A[0][1]*~-K
p (1..l).bsearch{|i|s=0;A.map{|w,d|i>=w&&s+=1+(i-w)/d};s>=K}
