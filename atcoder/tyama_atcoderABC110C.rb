#!/usr/bin/ruby
h,g=$<.map{|e|
	h=Hash.new{|h,k|h[k]=[]}
	e.chomp.each_char.with_index{|c,i|h[c]<<i}
	h.values.sort
}
puts h==g ? :Yes : :No
#FakeSolution h,g=$<.map{|e|h=Hash.new 0;e.chars{|c|h[c]+=1};h.values.sort};puts h==g ?:Yes: :No
