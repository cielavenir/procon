#!/usr/bin/ruby
n,k,t=gets.split.map &:to_i;p [t,k,n+k-t].min
