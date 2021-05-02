#!/usr/bin/ruby
puts Enumerator.new{|y|
	 t=i=1
	 loop{
	 	s=i.to_s.chars.map(&:to_i).reduce(:+)
	 	if s*t<i
	 		i+=9*t
	 		t*=10
		else
			y<<i
			i+=t
		end
	 }
}.take(gets.to_i)
