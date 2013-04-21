#!/usr/bin/ruby
def rec2c(a,n)
	if n==0 then 0
	else
		a.size.times{|i|
			if n>=a[i] && a.find{|e|(n-a[i])%e==0}
				r=rec2c(a,n-a[i])
				if r>=0 then return r+1 end
			end
		}
	end
end
a=[1,2]
2.step(47){|i|a<<a[i-1]+a[i-2]}
a.reverse!
p rec2c(a,gets.to_i)