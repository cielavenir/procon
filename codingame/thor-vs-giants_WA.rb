#!/usr/bin/ruby
STDOUT.sync = true
DIR=[
	['N',[0,-1]],
	['NE',[1,-1]],
	['E',[1,0]],
	['SE',[1,1]],
	['S',[0,1]],
	['SW',[-1,1]],
	['W',[-1,0]],
	['NW',[-1,-1]],
]
tx,ty = gets.split.map(&:to_i)
d = 0

loop{
	h,n = gets.split.map(&:to_i)
	f=false
	coor=n.times.map{gets.split.map(&:to_i)}
	if coor.all?{|x,y|
		(tx-x).abs>1 || (ty-y).abs>1
	}
		puts 'WAIT'
	else
		d_orig=d
		if 8.times{
			tx1=tx+DIR[d][1][0]
			ty1=ty+DIR[d][1][1]

			if 0<=tx1&&tx1<40 && 0<=ty1&&ty1<18 && coor.all?{|x,y|
				(tx1-x).abs>1 || (ty1-y).abs>1
			}
				tx=tx1
				ty=ty1
				puts DIR[d][0]
				d=(d+1)%8
				break
			end
			d=(d+1)%8
		}
			#cannot move
			puts 'STRIKE'
		end
	end
}