#!/usr/bin/ruby
def dfs(v,d,*a)
	if d<6
		0.step(a.max+1){|i|
			v[i]<<d
			dfs(v,d+1,*a,i)
			v[i].pop
		}
	else
		puts 0.step(a.max).map{|i|v[i]*''}*'.'
	end
end
dfs(Array.new(5){[]},1,-1)