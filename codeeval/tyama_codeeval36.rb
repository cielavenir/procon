#!/usr/bin/ruby
while gets
s=$_.chomp
raise 'malformed' unless s=~/^([^01]+)([01]+)$/
header=$1;mes=$2.split('')
str=''
while (n=mes.shift(3).join.to_i(2))>0
	while (x=mes.shift(n).join.to_i(2))!=(1<<n)-1
		str<<header[(1<<n)-n-1+x]
	end
end
puts str
end