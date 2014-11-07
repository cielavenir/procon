#!/usr/bin/ruby
def dfs(a,&block)
	return to_enum(:dfs,a) if !block_given?
	yield a[0] if a.size<2
	(a.size-1).times{|i|
		dfs(a[0..i]){|l|
			dfs(a[i+1..-1]){|r|
				yield l+r
				yield l*r
			}
		}
	}
end

p dfs($<.map(&:to_i)).max