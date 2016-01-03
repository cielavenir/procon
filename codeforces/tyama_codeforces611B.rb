#!/usr/bin/ruby
a,b=gets.split.map(&:to_i)
p Enumerator.new{|y|
	(1..1/0.0).each{|i|
		1.upto(i){|j|
			y<<('1'*j+'0'+'1'*(i-j)).to_i(2)
		}
	}
}.lazy.drop_while{|e|e<a}.take_while{|e|e<=b}.count