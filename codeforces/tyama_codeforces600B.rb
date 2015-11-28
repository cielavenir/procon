#!/usr/bin/ruby
gets
a=gets.split.map(&:to_i).sort
puts gets.split.map(&:to_i).map{|e|
	(0...a.size).bsearch{|i|a[i]>e}||a.size
}*' '