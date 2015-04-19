#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
if m<2 then p 0;exit end
a=n.times.map{gets.split.map(&:to_f)}
i=0
f=0
[*0...n].combination(m){|b|
	f0=0
	b.combination(2){|i,j|
		f0+=(a[i][0]-a[j][0])**2+(a[i][1]-a[j][1])**2+(a[i][2]-a[j][2])**2
	}
	if f<f0 then f=f0 end
}
p f