#!/usr/bin/ruby
#f=File.open('input.txt','rb')
f=$<
b,g=f.gets.split.map(&:to_i)
m=[b,g].min
b-=m;g-=m
p [g,m,b]
#File.write('output.txt','G'*g+'BG'*m+'B'*b)
puts 'G'*g+'BG'*m+'B'*b