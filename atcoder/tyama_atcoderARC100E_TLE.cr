#!/usr/bin/env crystal
n=gets.not_nil!.to_i
x=gets.not_nil!.split.map &.to_i
r=[0]*(1<<n)
m=r.dup
(1<<n).times{|i|
	j=i
	while j<1<<n
		r[j]=[r[j],x[i]+m[j]].max
		m[j]=[m[j],x[i]].max
		j=(j+1)|i
	end
}
(1...1<<n).each{|i|
	r[i]=[r[i],r[i-1]].max
	p r[i]
}
