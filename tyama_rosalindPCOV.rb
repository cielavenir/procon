#!/usr/bin/ruby
a=$<.map(&:chomp)
r=a.pop
l=r.size-1
while a.size>l
	a.length.times{|i|
		if r[-l..-1]==a[i][0,l]
			r+=a[i][-1,1]
			a.delete_at(i)
			break
		end
	}
end
puts r