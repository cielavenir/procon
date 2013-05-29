#!/usr/bin/ruby
while (n=gets.to_i)>0
a=n.times.map{gets.split.map(&:to_i)}
r=99999
0.step(a.size-2){|i|
	(i+1).step(a.size-1){|j|
		r=[r,Math.hypot(a[i][0]-a[j][0],a[i][1]-a[j][1])].min
	}
}
$><<(r<10000?"%.4f\n":"INFINITY\n")%r
end