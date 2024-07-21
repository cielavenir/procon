#!/usr/bin/ruby
def conv(n,b)
	# convert palindrome index to palindrome number.
	if n<b
		return n
	end
	n-=b
	i=1
	loop{
		z=b**i-b**~-i
		x=(b+1)*z
		if n<x
			if n<z
				return ((b**~-i+n).to_s+(b**~-i+n).to_s.reverse).to_i
			end
			n-=z
			d,r=n.divmod(b)
			return ((b**~-i+d).to_s+[*'0'..(b-1).to_s(b)][r]+(b**~-i+d).to_s.reverse).to_i
		end
		n-=x
		i+=1
	}
end

p conv(gets.to_i-1,10)
