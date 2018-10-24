#!/usr/bin/ruby
n=gets.to_i;print n<1?'0':'0.';n.times{|i|$><<'142857'[i%6]};puts
