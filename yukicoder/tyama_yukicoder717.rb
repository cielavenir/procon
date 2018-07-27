#!/usr/bin/ruby
gets
x,y=2.times.map{h=Hash.new 0;gets.chomp.chars{|c|h[c]+=1};h}
p [x['A'],y['A']].min+[x['B'],y['B']].min
