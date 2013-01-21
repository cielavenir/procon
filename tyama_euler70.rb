#!/usr/bin/ruby
require 'prime'
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
class Integer
	def totient2
		r=self.prime_division.reduce(1){|s,e|s*=(e[0]-1)*e[0]**(e[1]-1)}
		a=self.to_s.chars.map(&:to_i)
		b=r.to_s.chars.map(&:to_i)
		10.times{|i|
			if a.count{|e|e==i}!=b.count{|e|e==i} then return 99999999 end
		}
		return self/r.to_f
	end
end
p (12..9999999).lazy.map{|n|[n.totient2,n]}.min[1]