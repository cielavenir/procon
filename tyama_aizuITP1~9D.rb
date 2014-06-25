#!/usr/bin/ruby
s=gets.chomp
$<.drop(1).each{|l|
	x=l.split
	case x[0]
		when 'print'; puts s[x[1].to_i..x[2].to_i]
		when 'reverse'; s[x[1].to_i..x[2].to_i]=s[x[1].to_i..x[2].to_i].reverse
		when 'replace'; s[x[1].to_i..x[2].to_i]=x[3]
	end
}