#!/usr/bin/ruby
a,b=2.times.map{
	x,y=gets.split.map(&:to_i)
	gets.split.map(&:to_i).reverse.map.with_index{|e,i|e*y**i}.reduce(:+)
}
puts '=><'[a<=>b]