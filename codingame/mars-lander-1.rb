#!/usr/bin/ruby
STDOUT.sync = true

N = gets.to_i
land=N.times.map{
	gets.split.map(&:to_i)
}

loop{
	# HS: the horizontal speed (in m/s), can be negative.
	# VS: the vertical speed (in m/s), can be negative.
	# F: the quantity of remaining fuel in liters.
	# R: the rotation angle in degrees (-90 to 90).
	# P: the thrust power (0 to 4).
	x,y,hs,vs,f,r,p = gets.split.map(&:to_i)
	break if vs<-42
	# R P. R is the desired rotation angle. P is the desired thrust power.
	puts '0 0'
}
loop{puts '0 4'}