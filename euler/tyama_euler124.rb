#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	n,k=gets.split.map(&:to_i)
	p 1.step(n).map{|n|[n.prime_division.reduce(1){|s,e|s*=e[0]},n]}.sort[k-1][1]
}
__END__
1
100000 10000