#!/usr/bin/ruby
n=gets.to_i
s=n.times.map{gets.chomp.bytes}
g=n.times.map{[35]*n}
d={s=>0}
q=[s]
raise if n>3
 
while !q.empty?
	c=q.shift
	if c==g
		p d[c]
		exit
	end
	n.times{|i|
		#color=c.transpose[i]
		color=c[i]
		n.times{|j|
			#c0=c.dup
			c0=c.transpose
			c0[j]=color
			c0=c0.transpose
			if !d.has_key?(c0)
				d[c0]=d[c]+1
				q<<c0
			end
		}
	}
end
p -1
