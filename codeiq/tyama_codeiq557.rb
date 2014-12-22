#!/usr/bin/ruby
puts Enumerator.new{|y|
	a=b=1
	loop{
		a,b=a+b,a
		y<<a if a%a.to_s.chars.map(&:to_i).reduce(:+)==0
	}
}.take(11)*',' # 2,3,5,8,21,144,2584,14930352,86267571272,498454011879264,160500643816367088