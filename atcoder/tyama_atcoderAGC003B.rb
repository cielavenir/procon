#!/usr/bin/ruby
n=gets.to_i
a=$<.map(&:to_i)
r=0
(0...n).each{|i|
	r+=a[i]/2
	a[i]%=2
	if i<n-1 && a[i]>0 && a[i+1]>0
		a[i]-=1
		a[i+1]-=1
		r+=1
	end
}
p r