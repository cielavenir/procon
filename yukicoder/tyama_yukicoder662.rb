#!/usr/bin/ruby
h={}
r=[s=0]*5
5.times.map{|i|
	x,y=gets.split
	h[x]=[y.to_i,i]
}
n=[]
a=3.times.map{
	_h=Hash.new 0
	n0=gets.to_i
	n<<n0
	n0.times{_h[gets.chomp]+=1}
	_h
}
h.each{|x,(y,i)|
	r[i]+=5*a[0][x]*a[1][x]*a[2][x]
	s+=y*a[0][x]*a[1][x]*a[2][x]
}
=begin
a,b,c=3.times.map{n0=gets.to_i;n<<n0;n0.times.map{gets.chomp}}
a.product(b,c).map{|x,y,z|
	if x==y&&y==z
		r[h[x][1]]+=5
		s+=h[x][0]
	end
}
=end
p s*5.0/n[0]/n[1]/n[2]
p *r
