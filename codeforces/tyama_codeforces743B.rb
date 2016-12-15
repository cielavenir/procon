#!/usr/bin/ruby
n,k=gets.split.map &:to_i;r=1;(r+=1;k/=2)while k%2==0;p r
