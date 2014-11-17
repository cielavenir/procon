#!/usr/bin/ruby
gets.to_i.times{
	n,k=gets.split.map(&:to_i)
	puts n%(k+1)==1 ? :Lose : :Win
}