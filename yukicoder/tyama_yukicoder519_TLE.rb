#!/usr/bin/ruby
def parity(n) n<1 ? 0 : n%1+parity(n/2) end
n=gets.to_i
m=n.times.map{|i|gets.split.map &:to_i}
r=[0]*(1<<n)
(1<<n).times{|i|
	next if parity(i)==1
	n.times{|j|
		next if i|(1<<j)==i
		j.times{|k|
		r[i|(1<<j)|(1<<k)]=[r[i|(1<<j)|(1<<k)],r[i]+m[j][k]].max if i|(1<<k)!=i
		}
	}
}
p r[-1]
