#!/usr/bin/ruby
g=gets.to_i;d=g.to_s.chars.uniq;d.map{|x|d.map{|y|g=g.gcd 9*(x.to_i-y.to_i).abs}};p g
