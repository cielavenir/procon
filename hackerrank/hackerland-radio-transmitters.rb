#!/usr/bin/ruby
n,k,*a=`dd`.split.map(&:to_i)
a.sort!
r=0
prev=-Float::INFINITY
loop{
	base=a.bsearch{|e|e>prev}
	break if !base
	center=a[ ((0...n).bsearch{|i|a[i]>base+k}||n)-1 ]
	prev=center+k
	r+=1
}
p r
