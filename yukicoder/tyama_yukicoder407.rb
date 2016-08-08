#!/usr/bin/ruby
require'prime'
n,l=gets.split.map &:to_i
r=0
Prime.each(l/~-n){|e|r-=~l+e*~-n};p r