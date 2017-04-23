#!/usr/bin/ruby
require 'timeout'
def dfs(a)
	return to_enum(:dfs,a) if !block_given?
	yield a[0] if a.size<2
	(a.size-1).times{|i|
		dfs(a[0..i]){|l|
			dfs(a[i+1..-1]){|r|
				(puts :YES;exit) if l==r
				next if l<r
				yield l+r
				yield l-r
				yield l*r
				yield Rational(l,r)
			}
		}
	}
end

n,*a=`dd`.split.map(&:to_i)
begin
	#6_NOを0.5sで解けるまで高速化しましたが、7_NOは無理でした…
	timeout(4.5){
		a.permutation{|b|
			next if b[0]>b[-1]
			dfs(b).each{|e|
			}
		}
	}
	puts :NO
rescue Timeout::Error
	puts :NO
end
