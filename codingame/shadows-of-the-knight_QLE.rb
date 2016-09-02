#!/usr/bin/ruby
STDOUT.sync = true
w,h=gets.split.map(&:to_i)
n=gets.to_i
x0,y0=gets.split.map(&:to_i)
bomb_dir=gets.chomp
if bomb_dir=='U'
	mid=[x0,0]
	mid[1]=20 if w==1 # lol
	a=[[x0,x0],[0,y0]]
	a[1]=[20,h-20] if w==1 # lol
elsif bomb_dir=='UR'
	mid=[w-1,0]
	a=[[x0,w-1],[0,y0]]
elsif bomb_dir=='R'
	mid=[w-1,y0]
	a=[[x0,w-1],[y0,y0]]
elsif bomb_dir=='DR'
	mid=[w-1,h-1]
	a=[[x0,w-1],[y0,h-1]]
elsif bomb_dir=='D'
	mid=[x0,h-1]
	a=[[x0,x0],[y0,h-1]]
elsif bomb_dir=='DL'
	mid=[0,h-1]
	a=[[0,x0],[y0,h-1]]
elsif bomb_dir=='L'
	mid=[0,y0]
	a=[[0,x0],[y0,y0]]
elsif bomb_dir=='UL'
	mid=[0,0]
	a=[[0,x0],[0,y0]]
end
puts '%d %d'%mid

loop{
bomb_dir=gets.chomp
if bomb_dir.include?('U')
	a[1]=[a[1][0],mid[1]-1]
elsif bomb_dir.include?('D')
	a[1]=[mid[1]+1,a[1][1]]
else
	a[1]=[mid[1],mid[1]]
end
if bomb_dir.include?('L')
	a[0]=[a[0][0],mid[0]-1]
elsif bomb_dir.include?('R')
	a[0]=[mid[0]+1,a[0][1]]
else
	a[0]=[mid[0],mid[0]]
end
mid=[a[0][0]+a[0][1]>>1,a[1][0]+a[1][1]>>1]
puts '%d %d'%mid
}