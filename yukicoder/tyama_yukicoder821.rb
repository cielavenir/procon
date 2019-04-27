#!/usr/bin/ruby
n,k=gets.split.map &:to_i
p n*-~n-(n-=k)*-~n+2>>1
