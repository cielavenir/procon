#!/usr/bin/ruby
def gen_odd(n)
	m=n.times.map{[0]*n}
	r=n-1
	c=n/2
	i=0
	n.times{
		r=(r+1)%n
		m[r][c]=i+=1
		(n-1).times{
			r=(r+n-1)%n
			c=(c+1)%n
			m[r][c]=i+=1
		}
	}
	m
end
def gen_quad(n)
	z=n**2
	i=0
	m=n.times.map{[0]*n}
	n.times{|r|n.times{|c|
		j,k=i.divmod(n)
		j%=4
		k%=4
		m[r][c]=i+=1
		m[r][c]=z-m[r][c]+1 if (j==0||j==3)&&(k==1||k==2) or (j==1||j==2)&&(k==0||k==3)
	}}
	m
end
def gen_lux(n)
	m=n.times.map{[0]*n}
	o={l:[[4,1],[2,3]],u:[[1,4],[2,3]],x:[[1,4],[3,2]]}
	lux=(n/4+1).times.map{[:l]*(n/2)} + [[:u]*(n/2)] + (n/4-1).times.map{[:x]*(n/2)}
	lux[n/4][n/4],lux[n/4+1][n/4]=lux[n/4+1][n/4],lux[n/4][n/4]
	b=gen_odd(n/2).map{|e|e.map{|f|4*(f-1)}}
	n.times{|r|n.times{|c|
		br,xr=r.divmod(2)
		bc,xc=c.divmod(2)
		m[r][c]=b[br][bc]+o[lux[br][bc]][xr][xc]
	}}
	m
end
def gen_magicsquare(n)
	if n%2==1
		gen_odd(n)
	elsif n%4==0
		gen_quad(n)
	else
		gen_lux(n)
	end
end

puts gen_magicsquare(gets.to_i).map{|e|e*' '}