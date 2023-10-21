#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
puts a.include?(0)?0:'+-'[a.count{|e|e<0}%2]
