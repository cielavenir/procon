#!/usr/bin/ruby
puts gets.to_i.times.map{
	a,_,b=gets.split
	if a=='BEGINNING' then b[0]
	elsif a=='END' then b[b.size-1]
	elsif a=='MIDDLE' then b[b.size/2]
	end
}*''