#!/usr/bin/ruby
h=Hash.new(0);gets.chars{|c|h[c]+=1};puts (?A..?F).map{|c|h[c]}*' '