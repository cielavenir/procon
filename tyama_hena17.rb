#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/ebd9d7deb30c57447806
#http://nabetani.sakura.ne.jp/hena/ord17foldcut/
STDOUT.sync=true
RIGHT={
	'bl'=>lambda{|t,b,l,r|b*l},
	'br'=>lambda{|t,b,l,r|b*r},
	'tl'=>lambda{|t,b,l,r|t*l},
	'tr'=>lambda{|t,b,l,r|t*r},
}
LEFT={
	'L'=>lambda{|h,v,t,b,l,r|[h*2,v,t,b,h,l+r]},
	'R'=>lambda{|h,v,t,b,l,r|[h*2,v,t,b,l+r,h]},
	'T'=>lambda{|h,v,t,b,l,r|[h,v*2,v,t+b,l,r]},
	'B'=>lambda{|h,v,t,b,l,r|[h,v*2,t+b,v,l,r]},
}
while gets
	l,r=$_.chomp.split('-')
	p RIGHT[r][ *l.chars.reduce([1,1,0,0,0,0]){|s,e|s=LEFT[e][*s]}[2,4] ]
end