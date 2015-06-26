#!/usr/bin/ruby
n=gets.chomp
if idx=n.to_s.index('4')
	puts n[0,idx]+'3'+'9'*n[idx+1..-1].size
else
	puts n
end