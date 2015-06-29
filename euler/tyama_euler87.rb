#!/usr/bin/ruby
require 'prime'
M=50000000
a=Prime.each(9999).to_a
h={}
i=0;while a[i]**2 <= M
	j=0;while a[i]**2+a[j]**3 <= M
		k=0;while a[i]**2+a[j]**3+a[k]**4 <= M
			h[a[i]**2+a[j]**3+a[k]**4]=1
			k+=1
		end
		j+=1
	end
	i+=1
end
a=h.keys.sort
gets.to_i.times{
	n=gets.to_i
	p (0...a.size).bsearch{|i|a[i]>n}||a.size
}
__END__
1
50000000