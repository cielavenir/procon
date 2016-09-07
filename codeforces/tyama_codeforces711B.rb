#!/usr/bin/ruby
def chk(m)
	n=m.size
	x=y=0
	n.times{|i|
		x+=m[i][i]
		y+=m[i][n-i-1]
	}
	(
		[x]+[y]+
		m.map{|e|e.reduce(:+)}+
		m.transpose.map{|e|e.reduce(:+)}
	).group_by{|e|e}
end

n=gets.to_i
if n==1
	p 1
else
	m=$<.map{|e|e.split.map(&:to_i)}
	a=chk(m)
	if a.size!=2
		p -1
	else
		k=-a.map(&:first).minmax.reduce(:-)
		n.times{|i|n.times{|j|
			m[i][j]=k if m[i][j]==0
		}}
		a=chk(m)
		p a.size!=1 ? -1 : k
	end
end