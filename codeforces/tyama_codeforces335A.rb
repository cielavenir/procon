#!/usr/bin/ruby
h=Hash.new(0)
gets.chomp.chars{|c|h[c]+=1}
n=gets.to_i
if h.size>n
	p -1
	exit
end
a=h.sort_by{|e|-e[1]}
x=[1]*a.size
(n-a.size).times{x[a.each_with_index.max_by{|e,i|e.last*1.0/x[i]}.last]+=1}
p a.each_with_index.map{|e,i|(e.last+x[i]-1)/x[i]}.max
puts a.each_with_index.map{|e,i|e.first*x[i]}*''