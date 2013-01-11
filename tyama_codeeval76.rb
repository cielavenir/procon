#!/usr/bin/ruby
while gets
	a=$_.chomp.split(',')
	if a[0].length==a[1].length
		if a[0].length.times.any?{|i|
			a[0]==a[1][i..-1]+a[1][0...i]
		} then puts 'True';next end
	end
	puts 'False'
end