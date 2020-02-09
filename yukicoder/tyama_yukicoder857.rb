#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
p c<a ? c:c<b ? c-1:c-2
