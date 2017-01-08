#!/usr/bin/ruby
class Integer
	def comb(r)
		if r==0 then return 1 end
		n=self
		ret=1
		if r>n/2 then r=n-r end
		r.times{|i|
			ret=ret*(n-i)/(i+1)
		}
		return ret
	end
end
b=1.09/2.09
puts '%.3f'%[(3..6).reduce(0){|s,i|s+6.comb(i)*b**i*(1-b)**(6-i)}]
