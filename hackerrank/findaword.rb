#!/usr/bin/ruby
a=gets.to_i.times.flat_map{gets.chomp.tr("().,'\"",' ').gsub('-',' ').split}
gets.to_i.times{
	s=gets.chomp
	p a.count{|e|e==s}
}