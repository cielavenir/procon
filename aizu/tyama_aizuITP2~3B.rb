#!/usr/bin/ruby
gets
a=gets.split.map &:to_i
gets
$<.map{|e|
	x,y,z=e.split.map &:to_i
	p a[y...z].send(x==0 ? :min : :max)
}
