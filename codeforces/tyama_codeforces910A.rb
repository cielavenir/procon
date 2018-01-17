#!/usr/bin/ruby
n,m=gets.split.map &:to_i
s=gets.chomp
c=i=0
while c<n-1
	c=[c+m,n-1].min.downto(c+1).find{|j|s[j]==?1}
	if !c
		p -1
		exit
	end
	i+=1
end
p i
