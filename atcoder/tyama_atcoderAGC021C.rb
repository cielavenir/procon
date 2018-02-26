#!/usr/bin/ruby
N,M,a,b=gets.split.map &:to_i
z=N.times.map{['.']*M}
C=(N%2).step(N-1,2)
D=(M%2).step(M-1,2)
x=->i,j{a>0&&(z[i][j]='<';z[i][j+1]='>';a-=1)}
y=->i,j{b>0&&(z[i][j]='^';z[i+1][j]='v';b-=1)}

D.each{|j|x[0,j]} if N%2>0
C.each{|i|y[i,0]} if M%2>0
if N>2 && M>2 && N%2>0 && M%2>0 && a*b%4>0 && a>0&&b>0
	a+=1
	x[0,0];x[2,1];y[0,2]
end
C.each{|i|D.each{|j|
	if z[i][j+1]!='.'
	elsif a>0
		x[i,j];x[i+1,j]
	else
		y[i,j];y[i,j+1]
 	end
}}
if a+b>0
	puts :NO
else
	puts :YES
	puts z.map &:join
end
