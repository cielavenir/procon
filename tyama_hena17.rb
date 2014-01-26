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
	'L'=>lambda{|t,b,l,r|[t,b,l+r+1,l+r]},
	'R'=>lambda{|t,b,l,r|[t,b,l+r,l+r+1]},
	'T'=>lambda{|t,b,l,r|[t+b+1,t+b,l,r]},
	'B'=>lambda{|t,b,l,r|[t+b,t+b+1,l,r]},
}
while gets
	l,r=$_.chomp.split('-')
	p RIGHT[r].call(*l.chars.reduce([0,0,0,0]){|s,e|LEFT[e][*s]})
end