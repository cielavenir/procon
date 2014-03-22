#!/usr/bin/ruby
n=gets.to_i
s=$<.map(&:chomp)
a=s[0][0,1]
b=s[0][1,1]
t=n.times.map{|i|
	z=b*n
	z[i,1]=a
	z[n-i-1,1]=a
	z
}
puts a!=b&&s==t ? 'YES' : 'NO'