#!/usr/bin/ruby
n,k=gets.split.map &:to_i
a=$<.map{|e|e.split.map &:to_i}.sort_by{|e|-e[1]}
c=Hash.new s=r=0
l=[]
i=k-1
a.each{|m,v|
	if l.size>=k
		next if c.has_key?(m)
		i=i.downto(0).find{|j|c[l[j][0]]>1}
		break if !i
		s-=l[i][1]
		c[l[i][0]]-=1
		l.delete_at(i)
	end
	s+=v
	c[m]+=1
	l<< [m,v]
	r=[r,s+c.size**2].max
}
p r
