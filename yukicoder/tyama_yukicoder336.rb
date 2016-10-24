#!/usr/bin/ruby
#A001250
n=gets.to_i
a={-1=>k=0,0=>2};e=1
0.upto(n){|i|m=a[k+e]=0;e=-e
0.upto(i){|j|m+=a[k];a[k]=m%(10**9+7);k+=e}}
p n<3?0:[a[-n/2],a[n/2]][n%2]
