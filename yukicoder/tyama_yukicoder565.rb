#!/usr/bin/ruby
r,k=gets.split.map(&:to_i)
gets;m=$<.map{|e|e.chomp.chars}
if r==90
	m=m.reverse.transpose
elsif r==180
	m=m.reverse.map(&:reverse)
elsif r==270
	m=m.transpose.reverse
end
m.each{|e|
	puts [e.map{|c|c*k}*'']*k
}
