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
N,K=gets.split.map(&:to_i)
s=0
0.step(N){|n|
	0.step(n){|r|
		s+=1 if n.comb(r) > K
	}
}
p s
__END__
100 1000000