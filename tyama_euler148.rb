#!/usr/bin/ruby
m=10**9
d7=[]
while m>0
	d7.push m%7
	m/=7
end
r=0
mul=1
d7.reverse.each_with_index{|e,i|
	r+=28**(d7.size-1-i)*e*(e+1)/2*mul
	mul*=e+1
}
p r