#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i;l,r=[a,a.reverse].map{|b|s=[[n=0,i=-1]];r=b*2;b.map{|e|i+=1;s.pop while e<s[-1][0];r[e]=i-s[-1][1];s<<[e,i]};r};a.map{|e|n+=e*l[e]*r[e]};p n
