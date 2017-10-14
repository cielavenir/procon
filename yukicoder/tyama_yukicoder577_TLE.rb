#!/usr/bin/ruby
class Integer
	def pow_binary_mod(y,m)
		x = self
		z = 1
		while y!=0
			z=z*x%m if y&1!=0
			x=x*x%m
			y>>=1
		end
		z
	end
	def miller_rabin
		n=self.abs #todo#
		return true if n==2
		return false if n==1||n%2==0
		d=n-1
		s=0
		while d%2==0
			d/=2
			s+=1
		end
		a=1
		5.times{|_| #todo#
			a+=1
			a+=1 while a.gcd(n)!=1 #todo#
			r=a.pow_binary_mod(d,n)
			next if r==1||r==n-1
			if s.times.none?{|j|
				r=r.pow_binary_mod(2,n)
				r==n-1
			}
				return false
			end
		}
		return true
	end
end

def solve(n)
	return n>2 ? :Yes : :No if n%2==0
	m=2
	while m<n
		z=n-m;
		(1..60).each{|k|
			r=(1..z+1).bsearch{|e|e**k>z}-1
			next if m+r**k<n
			return :Yes if r.miller_rabin
		}
		m*=2
	end
	:No
end
gets.to_i.times{puts solve gets.to_i}
