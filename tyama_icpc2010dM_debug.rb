#!/usr/bin/ruby
#m.rb < M --> sort the content of M to see "the aperture".
a=[]
while(x=gets.to_i)>0
  a.push(x)
end
a.sort.each{|e|p e}