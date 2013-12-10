#!/usr/bin/ruby
def ite(a,n)
	b = Array.new(n+1)
	b[0] = 0
	1.step(n){|m|
		i = 0
		k = -1
		a.size.times{|i|
			#p a[i]
			if m >= a[i] && b[m-a[i]] >= 0 && (k < 0 || b[m-a[i]] + 1 < k)
				k = b[m-a[i]] + 1
			end
		}
		b[m] = k
	}
	b[n]
end

n=gets.to_i
puts ite(gets.split.map(&:to_i),n)