#!/usr/bin/ruby
n,k,*a=$<.read.split.map(&:to_i)
b=a[s=0]
(1...n).each{|i|
	if b+a[i]<k
		s+=k-b-a[i]
		a[i]=k-b
	end
	b=a[i]
}
p s
puts a*' '
