#!/usr/bin/ruby
require 'prime'
def pow(x,y)
	z=1
	while y!=0
		z=z*x%M if y&1!=0
		x=x*x%M
		y>>=1
	end
	z
end
M=10**9+7
E=Hash.new{|h,k|h[k]=[]}
N,K=gets.split.map(&:to_i)
if false
	gets.split.map(&:to_i).each{|e|
		e.prime_division.each{|n,p|E[n]<<p}
	}
else
	IO.popen('factor '+gets){|io|
		io.each{|line|
			line.split[1..-1].map(&:to_i).group_by{|e|e}.each{|k,v|E[k]<<v.size}
		}
	}
end
r=1
E.each{|k,v|
	n=v.sort_by{|e|-e}.take(K).reduce(:+)
	r=r*pow(k,n)%M
}
p r
