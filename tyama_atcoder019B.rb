#!/usr/bin/ruby
s=gets.chomp
l=s.size
case ((l+1)/2).times.count{|i|s[i,1]!=s[-i-1,1]}
	when 0 then p l*25-(l%2==1 ? 25 : 0)
	when 1 then p (l-2)*25+48
	else        p l*25
end