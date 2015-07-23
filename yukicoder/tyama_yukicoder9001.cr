#!/usr/bin/env crystal
s=gets
# sはnilである可能性があるので、ifで分岐させる
if s
	a,b=s.split.map{|e|e.to_i}
	print a+b
	puts " "+gets.not_nil! # not_nil!で外すことも可能
end