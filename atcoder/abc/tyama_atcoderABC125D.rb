#!/usr/bin/ruby
gets;a=gets.split.map &:to_i;n=a.count{|e|e<0};a.map! &:abs;p a.reduce(:+)-n%2*2*a.min
