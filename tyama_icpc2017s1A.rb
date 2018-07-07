#!/usr/bin/ruby
#https://jag2017summer-day1.contest.atcoder.jp/
n=gets.to_i
if n<52
	p n/2*3+n%2
else
	r=0
	(1..1/0.0).each{|x|
		c=[n,26**x].min
		r+=c*x
		break if 0==n-=c
	}
	p r
end
