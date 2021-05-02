#!/usr/bin/ruby
N,W,*A=`dd`.split.map &:to_i;h={0=>0};N.times{a,b,*A=A;h.to_a.map{|w,v|w+a<=W&&h[w+a]=[h[w+a]||0,v+b].max}};p h.values.max
