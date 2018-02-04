#!/usr/bin/ruby
gets
c=0
h=Hash.new 0
gets.split.each{|e|h[e]=d=h[e]+1;c+=d%2*2-1}
puts c>0 ? :Conan : :Agasa
