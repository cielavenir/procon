#!/usr/bin/ruby
NAME={'S'=>'SOUTH','E'=>'EAST','N'=>'NORTH','W'=>'WEST'}
DIR=%w(S E N W)
D=[[0,1],[1,0],[0,-1],[-1,0]]
T=[]
inv=false
breaker=false
d=0
r=[]

#input
gets
M=$<.map(&:chomp)
M.each_with_index{|e,i|
	if idx=e.index('@')
		START=[idx,i]
	end
	if idx=e.index('T')
		T<<[idx,i]
	end
}
if T.size==1
	T<<[M[T[0][1]].rindex('T'),T[0][1]]
end

#search
x,y=START
can_go=lambda{|y,x|
	M[y][x]!='#' && (breaker || M[y][x]!='X')
}
400.times{
	if !can_go[y+D[d][1],x+D[d][0]]
		if !inv
			d=0.upto(3).find{|e|can_go[y+D[e][1],x+D[e][0]]}
		else
			d=3.downto(0).find{|e|can_go[y+D[e][1],x+D[e][0]]}
		end
	end
	r<<NAME[DIR[d]]
	y+=D[d][1]
	x+=D[d][0]
	c=M[y][x]
	if c=='S'
		d=0
	elsif c=='E'
		d=1
	elsif c=='N'
		d=2
	elsif c=='W'
		d=3
	elsif c=='$'
		puts r
		exit
	elsif c=='I'
		inv=!inv
	elsif c=='B'
		breaker=!breaker
	elsif c=='T'
		x,y=T[T.index([x,y])^1]
	elsif c=='X'
		M[y][x]=' '
	end
}
puts :LOOP