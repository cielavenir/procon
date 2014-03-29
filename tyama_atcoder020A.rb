#!/usr/bin/ruby
a,b=gets.split.map{|e|e.to_i.abs}
if a>b
	puts :Bug
elsif a<b
	puts :Ant
else
	puts :Draw
end