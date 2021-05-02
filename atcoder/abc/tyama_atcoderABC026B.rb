#!/usr/bin/ruby
a=$<.drop(1).map(&:to_i).sort.reverse
n=0
a.each_with_index{|e,i|n+=e*e * (-1)**(i%2)}
p n*Math::PI