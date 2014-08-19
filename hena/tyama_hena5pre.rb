#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/0ddde0164a745cd09c34
#http://nabetani.sakura.ne.jp/hena/ord5railsontiles/
D=[[1,0],[0,1],[-1,0],[0,-1]]
C=[
	[0,1,2,3],
	[1,0,3,2],
	[3,2,1,0],
]

STDOUT.sync=true
while gets
	a=$_.chomp.chars.each_slice(3).map{|e|e.map(&:to_i)}
	d=1;x=1;y=0
	while 0<=x&&x<3&&0<=y&&y<3
		print (y*3+x+65).chr
		d=C[a[y][x]][d]
		x+=D[d][0];y+=D[d][1]
	end
	puts
end