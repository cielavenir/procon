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
	attr_reader :d
	def initialize(x,y,d,v)
		@x=x
		@y=y
		@d=d
		@v=v
		@v[@y][@x]='*'
		@route=[]
		@route<<[@x,@y]
	end
	def move
		d_orig=(@d+3)%4
		4.times{|i|
			@d=(d_orig+i)%4
			break if @v[@y+D[@d][0]][@x+D[@d][1]]=='.'
		}
		@y=@y+D[@d][0]
		@x=@x+D[@d][1]
		@v[@y][@x]='*'
		@route<<[@x,@y]
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
		maze=Maze.new(Z+1,Z-1,0,m)
		(days+1).times{maze.move}
		puts dir[maze.d]
		STDOUT.flush
	end
end