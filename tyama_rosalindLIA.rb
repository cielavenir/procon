#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
a=[1];(1<<n).times{|i|a=[1]+a.each_cons(2).map{|x,y|x+y}+[1]}
s=0;m.step(1<<n){|i|s+=a[i] * 0.25**i * 0.75**((1<<n)-i)};p s