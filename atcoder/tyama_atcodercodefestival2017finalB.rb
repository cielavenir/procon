#!/usr/bin/ruby
h={?a=>0,?b=>0,?c=>0};gets.chomp.chars{|c|h[c]+=1};x,y=h.values.minmax;puts y-x<2?:YES: :NO
