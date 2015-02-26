#!/usr/bin/env ruby
h=$<.map{|e|
	s=e.chomp
	[s,s.upcase].map{|f|f.bytes.each_with_object(Hash.new(0)){|e,s|s[e]+=1}}
}
y=[]
[*65..90,*97..122].each{|e|
	x=[h[0][0][e],h[1][0][e]].min
	y<<x
}
w=[]
[*65..90].each_with_index{|e,i|
	x=[h[0][1][e],h[1][1][e]].min
	w<<x-y[i]-y[i+26]
}
puts y.reduce(:+).to_s+' '+w.reduce(:+).to_s