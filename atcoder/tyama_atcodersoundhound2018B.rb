#!/usr/bin/ruby
n,l,r,*a=`dd`.split.map &:to_i
puts a.map{|e|[l,[e,r].min].max}*' '
