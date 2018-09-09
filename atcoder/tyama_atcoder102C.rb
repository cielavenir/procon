#!/usr/bin/ruby
n,k=gets.split.map &:to_i;p (n/k)**3+(~k%2*(n+k/2)/k)**3
