#!/usr/bin/ruby
gets.to_i.times{
	gets
	p gets.split.map(&:to_i).sort.chunk{|e|e}.reduce(0){|s,(k,v)|
		n=v.size
		s+n*(n-1)
	}
}