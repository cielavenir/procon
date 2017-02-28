#!/usr/bin/ruby
gets
puts gets.split.map(&:to_f).map{|f|
	r=0
	(2..1/0.0).find{|i|
		i<r+=Math.log(i,f)
	}
}*' '
