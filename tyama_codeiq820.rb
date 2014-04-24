#!/usr/bin/ruby
#derived from AOJ 0041
require 'rational'

class String
	def integer?
		Integer(self)!=nil rescue false
	end
end

def dfs(a,&block)
	return to_enum(:dfs,a) if !block_given?
	yield [a[0],a[0].to_s] if a.size<2
	(a.size-1).times{|i|
		dfs(a[0..i]){|l|
			dfs(a[i+1..-1]){|r|
				yield [l[0]+r[0],%Q((#{l[1]} + #{r[1]}))]
				yield [l[0]-r[0],%Q((#{l[1]} - #{r[1]}))]
				yield [l[0]*r[0],%Q((#{l[1]} * #{r[1]}))]
				yield [l[0].is_a?(Rational) || r[0].is_a?(Rational) ? l[0]/r[0] : Rational(l[0],r[0]),%Q((#{l[1]} / #{r[1]}))]
				yield ["#{l[0]}#{r[0]}".to_i,%Q(#{l[1]}#{r[1]})] if l[1].integer? and r[1].integer?
			}
		}
	}
end

h={}
[2,3,7,8].permutation{|e|
	dfs(e){|f|
		n=f[0]
		n=f[0].numerator if f[0].denominator==1
		if n.is_a?(Integer) && 1<=n && n<=99
			h[n]=true
		end
	}
}
puts [*1..99].reject{|e|h.has_key?(e)}*',' # 54,59,71,76,80,85,94,95