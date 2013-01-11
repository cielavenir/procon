#!/usr/bin/ruby
G=5
h={}
[*1..G*2].permutation{|a|
	if a[0]>G+1 then break end
	b=[]
	G.times{|i|b.push(a[G+i]+a[i]+a[(i+1)%G])}
	if G.times.all?{|i|b[i]==b[0]}
		c=[]
		G.times{|i|c.push([[a[G+i],a[i],a[(i+1)%G]].map(&:to_s)*'',i])}
		h[c.rotate(c.min_by{|e|e[0].to_i}[1]).transpose[0]*'']=1
	end
}
puts h.keys.select{|e|e.size==16}.max