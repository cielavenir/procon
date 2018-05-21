#!/usr/bin/ruby
N,*A=$<.map &:to_i
r=b=0
A.map{|e|
	(p -1;exit)if A[0]>0||b+1<e
	b>=e&&r+=b
	b=e
}
p r+b
