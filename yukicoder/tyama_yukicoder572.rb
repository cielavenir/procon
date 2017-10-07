#!/usr/bin/ruby
def mul(a,b)
	r=S.times.map{[0]*S}
	S.times{|y|
		S.times{|x|
			r[y][x]=S.times.reduce(0){|s,i|[s,a[y][i]+b[i][x]].max}
		}
	}
	r
end
n=gets.to_i-1
S=gets.to_i
e=S.times.map{|i|[0]*S}
a=$<.map{|e|e.split.map &:to_i}
while n>0
	e=mul(e,a) if n%2>0
	a=mul(a,a)
	n/=2
end
p e.map(&:max).max
