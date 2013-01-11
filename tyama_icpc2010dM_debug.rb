#!/usr/bin/ruby
#m.rb < M --> sort the content of M to see "the aperture".
a=Array.new
while(x=gets.to_i)>0
  a.push(x)
end
a.sort.each{|e|p e}