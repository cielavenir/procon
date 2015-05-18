#!/usr/bin/ruby
require 'bigdecimal'
N=gets.to_i
P=gets.to_i
p 1.step(N).select{|i|Math.sqrt(i).to_i**2!=i}.reduce(0){|s,i|s+=BigDecimal(i.to_s).sqrt(P-1).split[1][0...P].chars.map(&:to_i).reduce(:+)}
__END__
100
100