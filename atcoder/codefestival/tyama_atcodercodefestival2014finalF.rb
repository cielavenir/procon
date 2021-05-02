#!/usr/bin/ruby
require 'rational'
N=gets.to_i
a=N.times.map{gets.to_i}
diff=N.times.map{|i|a[i]%a[(i+N-1)%N].gcd(a[(i+1)%N])!=0} #解説による
b=N.times.map{|i|a[i].lcm(a[(i+1)%N])}
c=N.times.map{|i|b[i].gcd(b[(i+N-1)%N])}
#diff2は自分で求めた。ここまでは合っていたということか…。
diff2=N.times.map{|i|a[i]!=c[i]}
raise if diff!=diff2

p 3.times.map{|i|
	result=j=0
	while j<N
		if diff[(j+i)%N]
			j+=2
			result+=1
		end
		j+=1
	end
	result
}.min