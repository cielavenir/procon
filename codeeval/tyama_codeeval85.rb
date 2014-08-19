#!/usr/bin/ruby
#naive solution; will TLE with large k.
while gets
n,k,a,b,c,r=$_.split(',').map(&:to_i)
m=[a]
1.step(k-1){m<<(b*m.last+c)%r}
k.step(n-1){
	z={}
	m.each{|e|z[e]=1}
	(0..1/0.0).each{|i|
		if !z.has_key?(i)
			m<<i
			break
		end
	}
	m.shift
}
p m.last
end