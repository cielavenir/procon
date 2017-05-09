#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
z=[-Float::INFINITY]+(0...n).select{|i|a[i]==0}+[Float::INFINITY]
puts (0...n).map{|i|
	idx=((0...z.size).bsearch{|j|z[j]>=i}||z.size)-1
	[i-z[idx],z[idx+1]-i].min
}*' '
