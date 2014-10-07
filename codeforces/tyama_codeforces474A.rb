#!/usr/bin/ruby
keyboard=<<EOM
qwertyuiop
asdfghjkl;
zxcvbnm,./
EOM
.lines.map(&:chomp)
search=lambda{|c|
	keyboard.size.times{|y|
		keyboard[y].size.times{|x|
			return [x,y] if keyboard[y][x,1]==c
		}
	}
}
dir=gets.chomp=='R' ? -1 : 1
puts gets.chomp.each_char.map{|c|
	x,y=search[c]
	keyboard[y][(x+dir)%keyboard[y].size]
}*''