#!/usr/bin/ruby
N=gets.to_i-1
p 1.step(N).map{|a|1.step(N).map{|b|(a**b).to_s.chars.map(&:to_i).reduce(:+)}.max}.max
__END__
100