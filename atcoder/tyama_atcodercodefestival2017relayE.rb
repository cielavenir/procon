#!/usr/bin/ruby
N,P=gets.split.map &:to_i;k=0;Q=N.times.map{w,b=gets.split.map &:to_i;k+=b;(100-P)*w+P*b}.sort;s=0;p (1..N).find{|i|k*P<=s+=Q[-i]}
