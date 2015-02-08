#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
#http://nabetani.sakura.ne.jp/hena/ord28spirwa/

D=[ #Right,Up,Left,Down
	[0,1],
	[-1,0],
	[0,-1],
	[1,0],
]
dir=['E','N','W','S']

class Maze
	def initialize(x,y,v)
		@x=x
		@y=y
		@v=v
		@v[@y][@x]='*'
	end
	def move
		walls=D.each_with_index.map{|e,i|@v[@y+e[0]][@x+e[1]]=='*' ? 1<<i : 0}.reduce(:+)
		d=case walls
			when 8,8+4,8+6
				0
			when 1,1+8,1+12
				1
			when 2,2+1,2+9
				2
			when 4,4+2,4+3
				3
			else
				raise
		end
		@y=@y+D[d][0]
		@x=@x+D[d][1]
		@v[@y][@x]='*'
		d
	end
end

if __FILE__==$0
	Z=100
	while gets
		line=$_.chomp.split(':')
		n,e,s,w=line[0].split(',').map(&:to_i)
		days=line[1].to_i
		m=(Z*2).times.map{['.']*(Z*2)}
		m[Z][Z]='*'
		n.times{|i|m[Z-i-1][Z]='*'}
		e.times{|i|m[Z][Z+i+1]='*'}
		s.times{|i|m[Z+i+1][Z]='*'}
		w.times{|i|m[Z][Z-i-1]='*'}
		maze=Maze.new(Z+1,Z-1,m)
		days.times{maze.move}
		puts dir[maze.move]
		STDOUT.flush
	end
end