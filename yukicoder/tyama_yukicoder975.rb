#!/usr/bin/ruby
x=gets.to_i
y=gets.split.map(&:to_i)
z=gets.split.map(&:to_i)
if y.include? x
	if z.include? x
		puts :MrMaxValu
	else
		puts :MrMax
	end
else
	if z.include? x
		puts :MaxValu
	else
		p -1
	end
end
