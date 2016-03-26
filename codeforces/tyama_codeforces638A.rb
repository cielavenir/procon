#!/usr/bin/ruby
n,a=gets.split.map &:to_i;p [(n-a+2)/2,-~a/2][a%2]