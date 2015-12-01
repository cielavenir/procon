#!/usr/bin/ruby
gets.to_i.times{
	n,x,y=gets.split.map(&:to_i)
	puts n.times.select{|i|i%x==0&&i%y!=0}*' '
}