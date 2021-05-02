#!/usr/bin/ruby
(n,m),*a=$<.map{|e|e.split.map &:to_i}
p [1,-1].repeated_permutation(3).map{|e|a.map{|f|f.zip(e).reduce(0){|s,(x,y)|s+x*y}}.max(m).reduce(0,:+)}.max
#max(m)はRuby 2.2.0専用だが、sort[-m..-1]はmが0である可能性があるため不可
