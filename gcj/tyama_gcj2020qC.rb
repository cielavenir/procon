#!/usr/bin/ruby
t=gets.to_i
t.times{|i|
	print 'Case #%d: '%(i+1)
	n=gets.to_i
	r=[]
	c=[0,0]
	a=n.times.map{|i|gets.split.map(&:to_i)+[i]}.sort_by{|e|e[0]} # not e[1] ???
	if a.all?{|x,y,z|
		if c[0]<=x
			c[0]=y
			r<<['C']
		elsif c[1]<=x
			c[1]=y
			r<<['J']
		else
			break
		end
	}
		r2=[]
		n.times{|i|
			r2[a[i][-1]]=r[i]
		}
		puts r2*''
	else
		puts :IMPOSSIBLE
	end
}
