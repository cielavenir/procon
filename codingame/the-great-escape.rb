#!/usr/bin/ruby
STDOUT.sync = true

# w: width of the board
# h: height of the board
# playerCount: number of players (2 or 3)
# myId: id of my player (0 = 1st player, 1 = 2nd player, ...)
w, h, playerCount, myId = gets.split.map(&:to_i)
D=myId==0 ? 'RIGHT' : myId==1 ? 'LEFT' : 'DOWN' # lol lol

# game loop
{
	playerCount.times{
		# x: x-coordinate of the player
		# y: y-coordinate of the player
		# wallsLeft: number of walls available for the player
		x, y, wallsLeft = gets.split.map(&:to_i)
	}
	wallCount = gets.to_i # number of walls on the board
	wallCount.times{
		# wallX: x-coordinate of the wall
		# wallY: y-coordinate of the wall
		# wallOrientation: wall orientation ('H' or 'V')
		wallX, wallY, wallOrientation = gets.split
		wallX = wallX.to_i
		wallY = wallY.to_i
	}
	
	# Write an action using puts
	# To debug: STDERR.puts "Debug messages..."
	
	puts D # action: LEFT, RIGHT, UP, DOWN or "putX putY putOrientation" to place a wall
}