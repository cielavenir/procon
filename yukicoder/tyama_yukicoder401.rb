#!/usr/bin/ruby
n=gets.to_i**2;v,*a=n+1;a=[a.map{"%03d"%v-=1}]+a.transpose.reverse while v>1;puts a.map{|l|l.reverse*' '}