#!/usr/bin/ruby
N,A=gets.split.map &:to_i
p (1..32).map{|i|
	A*i-A+(0..1<<60).bsearch{|e|s=1;i.times{|j|s*=(e+j)/i};s>=N}
}.min
