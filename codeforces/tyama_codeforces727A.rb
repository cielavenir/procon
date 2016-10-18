#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
prev={a=>nil}
q=[a]
while !q.empty?
	cur=q.shift
	[cur*10+1,cur*2].each{|e|
		next if e>b
		if !prev.has_key?(e)
			prev[e]=cur
			q<<e
		end
	}
end
if prev[b]
	puts :YES
	x=[]
	while prev[b]
		x<<b
		b=prev[b]
	end
	x<<b
	p x.size
	puts x.reverse*' '
else
	puts :NO
end
