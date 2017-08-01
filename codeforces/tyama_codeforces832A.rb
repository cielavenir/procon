#!/usr/bin/ruby
n,k=gets.split.map &:to_i;puts [:NO,:YES][n/k%2]
