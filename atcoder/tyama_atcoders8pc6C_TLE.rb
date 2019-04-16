#!/usr/bin/ruby
h,w=gets.split.map &:to_i
m=h.times.map{gets.chomp*h}
q=[[0,0]]
m[0][0]='$'
while !q.empty?
	x,y=q.shift
	[[x+1,y],[x,y+1]].each{|nx,ny|
		if ny<m.size && nx<m[0].size && m[ny][nx]=='.'
			m[ny][nx]='$'
			q<<[nx,ny]
		end
	}
end
puts m[-1][-1]=='$' ? 'Yay!' : ':('
