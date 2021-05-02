#!/usr/bin/ruby
h={}
gets
gets.split.map(&:to_i).each{|e|
	e>>=1 while (e&1)==0
	h[e]=1
}
p h.size