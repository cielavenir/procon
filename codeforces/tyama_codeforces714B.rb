#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).group_by{|e|e}.map(&:first).sort
puts a.size<=2 || (a.size==3&&a[2]-a[1]==a[1]-a[0]) ? :YES : :NO