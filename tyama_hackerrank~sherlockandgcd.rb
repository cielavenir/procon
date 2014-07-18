#!/usr/bin/ruby
require 'rational'
gets.to_i.times{
	gets
	puts gets.split.map(&:to_i).reduce(:gcd)==1 ? :YES : :NO
}