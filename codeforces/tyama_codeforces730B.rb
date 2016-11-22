#!/usr/bin/ruby
STDOUT.sync=true
gets.to_i.times{
	n=gets.to_i
	r=[*1..n].minmax{|*e|
		puts '? %d %d'%e
		'<=>'.index(gets.chomp)-1
	}
	puts '! %d %d'%r
}
