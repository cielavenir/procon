#!/usr/bin/ruby
gets.to_i.times{|i|
	print "Case ##{i+1}: "
	n=gets.to_i
	if n==0
		puts :INSOMNIA
		next
	end
	i=n
	h={}
	loop{
		i.to_s.chars{|c|h[c]=1}
		break if h.size==10
		i+=n
	}
	p i
}