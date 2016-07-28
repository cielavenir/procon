#!/usr/bin/ruby
T=%w(2 3 4 5 6 7 8 9 10 J Q K A)
a=2.times.map{gets.to_i.times.map{
	T.index(gets.chomp[0..-2])
}}
pile=[[],[]]
match=0
while !a[0].empty? && !a[1].empty?
	pile[0]<<a[0].shift
	pile[1]<<a[1].shift
	if pile[0][-1]!=pile[1][-1]
		if pile[0][-1]>pile[1][-1]
			a[0]+=pile[0]+pile[1]
		else
			a[1]+=pile[0]+pile[1] # WTF?
		end
		pile[0]=[]
		pile[1]=[]
		match+=1
	else
		if a[0].size<3 || a[1].size<3
			puts :PAT
			exit
		end
		pile[0]+=a[0].shift(3)
		pile[1]+=a[1].shift(3)
	end
end
puts '%d %d'%[1+2.times.find{|i|!a[i].empty?},match]