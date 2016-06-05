#!/usr/bin/ruby
#coding:utf-8
ERDOS='Erdős'
s=gets.chomp
if s==ERDOS
	p 0
	exit
end
n=gets.to_i
papers=n.times.map{gets.chomp}
path=Hash.new{|h,k|h[k]=[]}
n.times{|i|
	a=gets.split
	a.combination(2){|x,y|
		path[x]<<[y,papers[i]]
		path[y]<<[x,papers[i]]
	}
}
q=[ERDOS]
prev={ERDOS=>[nil,nil]}
while !q.empty?
	cur=q.shift
	path[cur].each{|name,paper|
		if !prev.has_key?(name)
			prev[name]=[cur,paper]
			q<<name
		end
	}
end
if prev.has_key?(s)
	r=[]
	cur,paper=prev[s]
	while cur
		r<<paper
		cur,paper=prev[cur]
	end
	p r.size
	puts r
else
	puts :infinite
end