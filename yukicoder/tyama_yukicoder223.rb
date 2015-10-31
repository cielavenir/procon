#!/usr/bin/ruby
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
n,x,y,z=gets.split.map{|e|e.to_i-1}
b=gen_quad(n+1).map{|e|e.map{|f|f-1}}
k=z^b[y][x]
puts b.map{|e|e.map{|f|(f^k)+1}*' '}