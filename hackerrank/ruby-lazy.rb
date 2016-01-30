#!/usr/bin/ruby
require 'prime'
p Enumerator.new{|y|
	Prime.each{|e|
		y<<e if e.to_s==e.to_s.reverse
	}
}.take(gets.to_i)