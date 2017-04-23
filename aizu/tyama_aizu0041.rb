#!/usr/bin/ruby

def dfs(a)
	return to_enum(:dfs,a) if !block_given?
	yield [a[0],a[0].to_s] if a.size<2
	(a.size-1).times{|i|
		dfs(a[0..i]){|l|
			dfs(a[i+1..-1]){|r|
				yield [l[0]+r[0],%Q((#{l[1]} + #{r[1]}))]
				yield [l[0]-r[0],%Q((#{l[1]} - #{r[1]}))]
				yield [l[0]*r[0],%Q((#{l[1]} * #{r[1]}))]
			}
		}
	}
end

while (a=gets.split.map(&:to_i))!=[0,0,0,0]
	if a.permutation.none?{|e|
		if r=dfs(e).find{|n,s|n==10}
			puts r[1]
			true
		end
	}
		p 0
	end
end
