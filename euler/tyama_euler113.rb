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
gets.to_i.times{
	n=gets.to_i
	p ((n+9).comb(9)-1+(n+10).comb(10)-n-1-n*9)%(10**9+7)
}
__END__
1
100