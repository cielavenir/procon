#!/usr/bin/ruby
STDOUT.sync = true

loop{
    x, y, next_checkpoint_x, next_checkpoint_y, next_checkpoint_dist, next_checkpoint_angle = gets.split.map(&:to_i)
    opponent_x, opponent_y = gets.split.map(&:to_i)
    
    # Write an action using puts
    # To debug: STDERR.puts "Debug messages..."
    speed = next_checkpoint_angle.abs>90 ? 0 : 100
	if next_checkpoint_angle.abs<1 && next_checkpoint_dist>4000
		speed=:BOOST
	elsif next_checkpoint_dist<1000
		speed=20
	end

    puts [next_checkpoint_x, next_checkpoint_y, speed]*' '
}