#!/usr/bin/ruby
gets.to_i.times{
	if !(gets.chomp=~/^\((.+), (.+)\)$/)
		puts 'Invalid'
	elsif $1.end_with?('.')||$2.end_with?('.')
		puts 'Invalid'
	else
		x=$1;y=$2
		x=~/(\d+)/
		if $1.start_with?('0')&&$1!='0'
			puts 'Invalid'
			next
		end
		y=~/(\d+)/
		if $1.start_with?('0')&&$1!='0'
			puts 'Invalid'
			next
		end
		x=x.to_f
		y=y.to_f
		puts -90<=x&&x<=90 && -180<=y&&y<=180 ? 'Valid' : 'Invalid'
	end
}