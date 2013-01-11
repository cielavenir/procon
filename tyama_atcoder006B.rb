#!/usr/bin/ruby
a=ARGF.read.split("\n")
n,l=a[0].split.map(&:to_i)
e=a[l+1].index('o')/2
l.step(1,-1){|i|
	if e>0&&a[i][2*e-1,1]=='-' then e-=1
	elsif e<n-1&&a[i][2*e+1,1]=='-' then e+=1 end
}
puts e+1