#!/usr/bin/ruby
n,q,*a=`dd`.split.map &:to_i;a.map{|e|q=(2+q*e+2*q+2*e)%(10**9+7)};p q
