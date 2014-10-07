#!/usr/bin/ruby
h=Hash.new(0)
gets.split.each{|e|h[e.to_i]+=1}
sizes=h.values.sort
if sizes==[2,4]||sizes==[6]
	puts 'Elephant'
elsif sizes==[1,1,4]||sizes==[1,5]
	puts 'Bear'
else
	puts 'Alien'
end