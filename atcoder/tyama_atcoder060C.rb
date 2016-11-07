#!/usr/bin/ruby
N,A,*X=`dd`.split.map &:to_i;h=Hash.new 0;h[0]=1;X.map{|e|[*h].map{|k,v|h[k+e-A]+=v}};p~-h[0]
