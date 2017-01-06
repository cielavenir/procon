#!/usr/bin/ruby
def median(a)
	return nil if a.empty?
	if a.size%2==0
		(a[a.size/2-1]+a[a.size/2])/2.0
	else
		a[a.size/2]
	end
end

n=gets.to_i
x=gets.split.map(&:to_i).sort
a=x.shift(n/2)
b=x.pop(n/2)
p median(a).to_i
p median(a+x+b).to_i
p median(b).to_i
