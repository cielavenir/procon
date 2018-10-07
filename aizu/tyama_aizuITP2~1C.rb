#!/usr/bin/ruby
A=[]
c=0
gets.to_i.times{
	a=gets.split.map &:to_i
	if a[0]==0
		A.insert(c,a[1])
	elsif a[0]==1
		c+=a[1]
	else
		A.delete_at(c)
	end
}
p *A
