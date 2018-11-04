#!/usr/bin/ruby
N,*A=$<.map &:to_i;A.sort!;n=N/2-1
p 2*(A[n+2..-1]||[]).reduce(0,:+)-2*A[0,n].reduce(0,:+)+A[n+1]-A[n]-(N%2<1 ? 0 : [A[n]+A[n+2],2*A[n+1]].min)
