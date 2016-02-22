#!/usr/bin/ruby
def pair(s)
	pairs=[]
	stk=[]
	s.chars.each_with_index{|c,i|
		if c=='('
			stk<<i
		else
			pairs<<[stk.pop,i]
		end
	}
	pairs
end
s=gets.chomp
k=gets.to_i
raise if s.size>10
pairs=pair(s)
p 2*(1<<(s.size-1)).times.count{|i|
	r=[0]
	(s.size-1).times{|j|r[j+1]=i[j]}
	pairs.all?{|s,t|
		x=r[s..t].reduce(:+)
		y=(t-s+1)-x
		(x-y).abs<=k
	}
}