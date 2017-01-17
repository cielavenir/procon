#!/usr/bin/ruby
F=5*10**10
def query(x,y)
	puts [('%.15f'%x)[0,20],('%.15f'%y)[0,20]]*' '
	STDOUT.flush
	r=gets.chomp
	exit if r=='found'||r=='kill'
	r
end
def near
	8.times{|i|8.times{|j|
		x,y=[i,j].map{|e|62500+e*125000}
		return [x,y] if query(x,y)=='close'
	}}
	exit
end
def range(l,r,f,y)
	(l*F..r*F).bsearch{|m|(query(m.to_f/F,y)=='close')==f}.to_f/F
end
x,y=near
xl=range(x-250000,x,true,y)
xr=range(x,x+250000,false,y)
x=((xl+xr)/2).floor
dy=Math.sqrt([0,1e10-(x-xl)**2].max).floor
query(x,y+dy)
query(x,y-dy)
