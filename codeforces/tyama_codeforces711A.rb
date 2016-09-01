#!/usr/bin/ruby
gets;a=$<.map(&:chomp)
if a.any?{|e|
	if e[0,2]=='OO'
		e[0,2]='++'
	elsif e[3,2]=='OO'
		e[3,2]='++'
	else
		false
	end
}
	puts :YES
	puts a
else
	puts :NO
end