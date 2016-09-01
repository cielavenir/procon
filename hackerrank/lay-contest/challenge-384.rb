#!/usr/bin/ruby
T={'A'=>4,'B'=>7,'C'=>17,'D'=>22}
gets.to_i.times{
	x,y=2.times.map{gets.split[1..-1].map(&T.method(:[])).reduce(0,:+)}
	puts [:DOTEN,:WIN,:LOSE][x<=>y]
}