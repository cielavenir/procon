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
b=0.12
puts '%.3f'%[(0..2).reduce(0){|s,i|s+10.comb(i)*b**i*(1-b)**(10-i)}]
puts '%.3f'%[(2..10).reduce(0){|s,i|s+10.comb(i)*b**i*(1-b)**(10-i)}]
