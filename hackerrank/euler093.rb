#!/usr/bin/ruby
require 'rational'

def dfs(a,&block)
	return to_enum(:dfs,a) if !block_given?
	yield [a[0],a[0].to_s] if a.size<2
	(a.size-1).times{|i|
		dfs(a[0..i]){|l|
			dfs(a[i+1..-1]){|r|
				yield [l[0]+r[0],%Q((#{l[1]} + #{r[1]}))]
				yield [l[0]-r[0],%Q((#{l[1]} - #{r[1]}))]
				yield [l[0]*r[0],%Q((#{l[1]} * #{r[1]}))]
				yield [l[0].is_a?(Rational) || r[0].is_a?(Rational) ? l[0]/r[0] : Rational(l[0],r[0]),%Q((#{l[1]} / #{r[1]}))] if r[0]!=0
			}
		}
	}
end

gets
A=gets.split.map(&:to_i)
h={}
A.permutation{|e|
	dfs(e){|f|
		n=f[0]
		n=f[0].numerator if f[0].denominator==1
		if n.is_a?(Integer)
			h[n]=true
		end
	}
}
p (1..1/0.0).find{|i|!h.has_key?(i)}-1