#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp.tr("().,'\"",' ').gsub('-',' ').split}.flatten
gets.to_i.times{
	s=gets.chomp
	p a.count{|e|e==s}
}