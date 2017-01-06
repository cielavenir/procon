#!/usr/bin/ruby
def median(a)
	return nil if a.empty?
	if a.size%2==0
		(a[a.size/2-1]+a[a.size/2])/2.0
	else
		a[a.size/2]
	end
end

gets
x=gets.split.map(&:to_i)
y=gets.split.map(&:to_i)
x=x.zip(y).flat_map{|a,b|[a]*b}.sort
n=x.size

a=x.shift(n/2)
b=x.pop(n/2)
q1=median(a)
q3=median(b)
puts '%.1f'%[q3-q1]
