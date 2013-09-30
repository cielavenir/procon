#!/usr/bin/ruby
a=gets.to_i.times.map{gets.chomp.tr("().,'\"",' ').gsub('-',' ').split}.flatten
gets.to_i.times{
	s=gets.chomp
	p a.count{|e|
		fidx=0
		lidx=e.size-1
		fidx=s.size if e.start_with?(s)
		lidx=e.size-1-s.size if e.end_with?(s)
		e[fidx..lidx].include?(s)
	}
}