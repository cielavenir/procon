#!/usr/bin/ruby
h=Hash.new(0)
gets.chars{|c|h[c]+=1}
p [h[?t],h[?r],h[?e]/2].min