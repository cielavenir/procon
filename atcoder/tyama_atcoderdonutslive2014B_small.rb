#!/usr/bin/ruby
n=gets.to_i
raise if n>10**8
i=7
r=0
while i<=n
	r+=1 if i.to_s.each_char.all?{|c|('1'..'7').include?(c)}
	i+=7
end
p r