#!/usr/bin/ruby
v=0
m=gets.to_i
if m<100
	v=0
elsif m<6000
	v=m*10/1000
elsif m<35000
	v=m/1000+50
elsif m<=70000
	v=(m/1000-30)/5+80
else
	v=89
end
puts "%02d"%v