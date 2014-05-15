#!/usr/bin/ruby
s=[]
siz=0
Q,L=gets.split.map(&:to_i)
Q.times{
	query=gets.split
	if query[0]=='Push'
		s<<[query[2].to_i,query[1].to_i]
		siz+=query[1].to_i
		if siz>L
			puts 'FULL'
			exit
		end
	elsif query[0]=='Pop'
		pop=query[1].to_i
		if pop>siz
			puts 'EMPTY'
			exit
		end
		while pop>0
			dec=[pop,s.last[1]].min
			pop-=dec
			s.last[1]-=dec
			siz-=dec
			s.pop if s.last[1]==0
		end
	elsif query[0]=='Top'
		if siz==0
			puts 'EMPTY'
			exit
		end
		p s.last[0]
	elsif query[0]=='Size'
		puts siz
	else
		raise
	end
}
puts 'SAFE'