#!/usr/bin/ruby
D=[[1,-2],[1,2],[2,-1],[2,1]]
M=$<.map{|e|e.chomp.chars}
puts 9.times.all?{|y|9.times.all?{|x|
	D.all?{|dx,dy|x+dx<0||9<=x+dx || y+dy<0||9<=y+dy || M[y][x]!=M[y+dy][x+dx]}
}}&&[M,M.transpose].all?{|z|z.all?{|e|e.uniq==e}}?:Yes: :No
