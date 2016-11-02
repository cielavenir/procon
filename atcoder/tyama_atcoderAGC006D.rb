#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
p (1..2*n).bsearch(&->x{
	b=a.map{|e|e<x}
	n.times{|i|[-1,1].map{|f|z=n-~i*f-1;return b[z]if b[z]==b[z-f]}};b[0]
})-1
