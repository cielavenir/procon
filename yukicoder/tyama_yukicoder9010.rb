#!/usr/bin/ruby
def leap?(year)
	return true if year%400==0
	return false if year%100==0
	year%4==0
end
puts leap?(gets.to_i) ? :Yes : :No
