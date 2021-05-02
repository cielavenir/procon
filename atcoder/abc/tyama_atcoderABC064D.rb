#!/usr/bin/ruby
x=y=k=j=0
gets
s=gets.chomp
s.size.times{|i|
	if s[i]=='('
		j+=1
	else
		j-=1
		x=[x,j].min
	end
	if s[s.size-1-i]==')'
		k+=1
	else
		k-=1
		y=[y,k].min
	end
}
puts '('*-x+s+')'*-y
