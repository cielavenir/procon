#!/usr/bin/ruby
require 'bio'
s=Bio::Sequence::NA.new(gets.chomp)
t=gets.chomp
(1..100).each{|i|
	begin
		x=s.translate(1,i)
		if x==t||x==t+'*' then p i;exit end
	rescue;end
}
raise "need more high table index limit or condition check is wrong"