#!/usr/bin/ruby
require'prime'
n,k=gets.split.map &:to_i
r=rn=0
o=Hash[n.prime_division]
(2...n).each{|i|
	q=i.prime_division
	k0=k
	q.each{|n,p|k0-=[o[n].to_i,p].min}
	if k0<=0
		r0=q.map{|n,p|p+1}.reduce(:*)
		if r<r0
			r=r0
			rn=i
		end
	end
}
p rn
