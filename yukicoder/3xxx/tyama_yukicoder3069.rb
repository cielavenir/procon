#!/usr/bin/ruby
a,b=gets.split.map &:to_i
s=gets.chomp.gsub(/[LR]+/){|e|e[-1]}.gsub(/[UD]+/){|e|e[-1]}
if !s.include?('L')||!s.include?('U')||s.end_with?('RD')||s.end_with?('DR')
	p -1
else
	p 6
	s=s.gsub(/[DR]/,'')
	a,b=b,a if s.end_with?('L')
	r=[[0,1],[a+2,0],[a+1,1],[a+1,b],[a,b+1],[a-1,b]]
	r=r.map &:reverse if s.end_with?('L')
	puts r.sort.map{|e|e*' '} # somehow sort is required...
end
