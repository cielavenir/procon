#!/usr/bin/ruby
f=->a,b{50*a+250*a/(4+b)}
n=gets.to_i
a=gets.split.map(&:to_i)
h=Hash.new([0,0])
ac=Hash.new(0)
perprob=Hash.new{|h,k|h[k]=[0]*n}
gets.to_i.times{|i|
	x,y=gets.split
	idx=y.ord-65
	score=f.(a[idx],ac[idx]+=1)
	perprob[x][idx]=score
	#このhをBITで管理できれば
	h[x]=[h[x][0]-score,i]
}
h.sort_by{|k,v|v}.each.with_index{|(k,v),i|
	puts '%d %s %s %d'%[i+1,k,perprob[k]*' ',-v[0]]
}
