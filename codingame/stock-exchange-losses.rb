#!/usr/bin/ruby
gets
ma=0
r=0
gets.split.map(&:to_i).each{|e|
	ma=[ma,e].max
	r=[r,e-ma].min
}
p r