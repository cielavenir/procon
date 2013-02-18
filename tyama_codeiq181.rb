#!/usr/bin/ruby
def CombinationGenerator(n,k)
	return Enumerator.new{|y|
		indexes=k.times.map{|i|i}
		while indexes[0]<=n-k
			y << indexes
			i=k-1
			while i>0&&indexes[i]==n-k+i
				i-=1
			end
			indexes[i]+=1
			i+=1
			while i<k
				indexes[i]=indexes[i-1]+1
				i+=1
			end
		end
	}
end
CombinationGenerator(5,2).each{|a|p a}