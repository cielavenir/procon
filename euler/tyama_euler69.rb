#!/usr/bin/ruby
require 'prime'
class Integer
	def totient() self.prime_division.reduce(1){|s,e|s*=(e[0]-1)*e[0]**(e[1]-1)} end
end
gets.to_i.times{
	p (2...gets.to_i).max_by{|n|n/n.totient.to_f}
}
__END__
1
1000000