#!/usr/bin/ruby
while(n=gets.to_i)>0
	idx=[]
	m=[]
	n.times{m<<gets.split.map(&:to_i);idx<<[0]*n}
	m.size.times{|i|idx[i][m[i].each_with_index.min[1]]+=1}
	m.size.times{|i|idx[m.transpose[i].each_with_index.max[1]][i]+=2}
	k=0
	n.times{|i|n.times{|j|k=m[i][j] if idx[i][j]==3}}
	p k
end