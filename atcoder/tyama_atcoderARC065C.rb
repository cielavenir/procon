#!/usr/bin/ruby
T=%w(dream dreamer erase eraser).map(&:reverse)
s=gets.chomp.reverse
c=0
while c<s.size
	k=T.find{|e|s[c,e.size]==e}
	if !k
		puts :NO
		exit
	end
	c+=k.size
end
puts :YES
