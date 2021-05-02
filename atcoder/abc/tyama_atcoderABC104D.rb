#!/usr/bin/ruby
M=10**9+7;a=[1,0,0,0];gets.chomp.chars{|c|(i='ABC'.index c)?a[i+1]+=a[i]:a=(0..3).map{|i|a[i]*3%M+(i<1?0:a[i-1])}};p a[3]%M
#a=[1,0,0,0];gets.chomp.chars{|c|*r=*(x='.ABC'.index c)||(0..3);r.reverse.map{|i|a[i]=(a[i]*(x ?1:3)+(i<1?0:a[i-1]))%(10**9+7)}};p a[3]
