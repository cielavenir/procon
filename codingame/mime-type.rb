#!/usr/bin/ruby
N = gets.to_i
Q = gets.to_i
h={}
N.times do
	# EXT: file extension
	# MT: MIME type.
	ext, mt = gets.split
	h[ext.downcase]=mt
end
Q.times do
	fname = gets.chomp
	if fname.include?('.')&&fname.rindex('.')!=fname.size-1
		puts h[fname.split('.').last.downcase]||'UNKNOWN'
	else
		puts 'UNKNOWN'
	end
end