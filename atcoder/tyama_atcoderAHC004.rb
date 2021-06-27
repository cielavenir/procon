#!/usr/bin/ruby
srand(12345678901234567890)
n,m=gets.split.map &:to_i
a=m.times.map{gets.chomp}.sort_by{|e|e.size}
lines=[]
s=''
a.each{|e|
	if s.size+e.size>n
		while s.size<n
			s << [*'A'..'H'].sample
		end
		lines << s
		s = ''
		if lines.size == n
			break
		end
	end
	s += e
}
puts lines
