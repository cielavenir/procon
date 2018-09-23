#!/usr/bin/ruby
_,_,x,y=gets.split.map &:to_i;a=gets.split.map &:to_i;b=gets.split.map &:to_i
puts [x,*a].max<[y,*b].min ? 'No War' : :War
