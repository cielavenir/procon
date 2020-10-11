#!/usr/bin/ruby
n,l=gets.split.map &:to_i;p 2.pow((n+l-1)/l,998244353)-1
