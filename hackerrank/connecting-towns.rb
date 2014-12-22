#!/usr/bin/ruby
gets.to_i.times{
	gets
	p gets.split.map(&:to_i).reduce(:*)%1234567
}