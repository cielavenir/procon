#!/usr/bin/ruby
def chk(a)
	9.times{|h|9.times{|w|
		[[0,1],[1,0],[1,1],[1,-1]].each{|dx,dy|
			ex=w+dx*6
			ey=h+dy*6
			next unless 0<=ex&&ex<9 && 0<=ey&&ey<9
			return false if 7.times.all?{|i|
				a[h+dy*i][w+dx*i]=='.'
			}
		}
	}}
	return true
end
loop{
	x=[*0..80].sample(11)
	a=9.times.map{'.........'}
	x.each{|e|a[e/9][e%9]='#'}
	if chk(a)
		puts a
		exit
	end
}
__END__
....#....
.....#...
#.....#..
...#.....
.....#...
..#....#.
.#..#...#
......#..
.....#...
