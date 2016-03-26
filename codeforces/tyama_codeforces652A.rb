#!/usr/bin/ruby
g,h,a,b=$<.read.split.map(&:to_i)
r=(15..1e6).find{|t|
	if 10<t%24&&t%24<=22
		g+=a
	else
		g-=b
	end
	g>=h
}
p r ? r/24 : -1