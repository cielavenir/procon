#!/usr/bin/ruby
require'prime'
r=Hash.new 0
H,W=gets.split.map &:to_i
M=$<.map{|e|e.chomp}
H.times{|h|W.times{|w|if M[h][w]==?o
	M[h][w]=?.;q=[h*W+w];l={q[0]=>1}
	while !q.empty?
		y,x=q.shift.divmod W
		(-1..1).each{|dy|(-1..1).each{|dx|
			ny=y+dy;nx=x+dx
			if 0<=ny&&ny<H && 0<=nx&&nx<W && M[ny][nx]==?o
				M[ny][nx]=?.;q<<ny*W+nx;l[ny*W+nx]=1
			end
		}}
	end
	x,y=l.size.prime_division.find{|n,p|p%2>0}
	r[x]+=1
end}}
puts [3,nil,11].map{|e|r[e]}*' '
