#!/usr/bin/ruby
gets.to_i.times{
	s=gets.chomp
	if s=~/^([0-9]+)\.([0-9]+)\.([0-9]+)\.([0-9]+)$/ && $1.to_i<256 && $2.to_i<256 && $3.to_i<256 && $4.to_i<256
		puts 'IPv4'
	elsif s=~/^[0-9a-f]{,4}:[0-9a-f]{,4}:[0-9a-f]{,4}:[0-9a-f]{,4}:[0-9a-f]{,4}:[0-9a-f]{,4}:[0-9a-f]{,4}:[0-9a-f]{,4}$/
		puts 'IPv6'
	else
		puts 'Neither'
	end
}