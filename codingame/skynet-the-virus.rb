#!/usr/bin/ruby
STDOUT.sync=true
N,L,E=gets.split.collect(&:to_i)
link=Hash.new{|h,k|h[k]=[]}
L.times{
	x,y=gets.split.map(&:to_i)
	link[x]<<y
	link[y]<<x
}
gateways=E.times.map{gets.to_i}
loop{
	agent=gets.to_i
	depth={agent=>0}
	prev={agent=>nil}
	q=[agent]
	while !q.empty?
		cur=q.shift
		link[cur].each{|e|
			if !depth.has_key?(e)
				depth[e]=depth[cur]+1
				prev[e]=cur
				q<<e
			end
		}
	end
	gateway=gateways.min_by{|e|depth[e]||Float::INFINITY}
	x,y=gateway,prev[gateway]
	# for ambush achievement;
	# remove this line for skynet-strikes-back 50% solution.
	x,y=y,prev[y] while y!=agent
	link[x].delete(y)
	link[y].delete(x)
	puts '%d %d'%[x,y]
}