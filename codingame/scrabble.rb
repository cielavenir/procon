#!/usr/bin/ruby
T={"e"=>1, "a"=>1, "i"=>1, "o"=>1, "n"=>1, "r"=>1, "t"=>1, "l"=>1, "s"=>1, "u"=>1, "d"=>2, "g"=>2, "b"=>3, "c"=>3, "m"=>3, "p"=>3, "f"=>4, "h"=>4, "v"=>4, "w"=>4, "y"=>4, "k"=>5, "j"=>8, "x"=>8, "q"=>10, "z"=>10}
a=gets.to_i.times.map{gets.chomp}
h=Hash.new(0)
gets.chomp.chars{|c|h[c]+=1}
puts a.select{|e|
	g=Hash.new(0)
	e.chars{|c|g[c]+=1}
	g.all?{|k,v|h[k]>=v}
}.map.with_index{|e,i|
	[e.chars.map(&T.method(:[])).reduce(:+),-i,e]
}.max.last