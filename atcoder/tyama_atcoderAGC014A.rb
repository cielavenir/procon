#!/usr/bin/ruby
a,b,c=gets.split.map &:to_i
if a==b&&b==c
	p [-1,0][a%2]
else
	p (0..1/0.0).find{|i|a%2>0||b%2>0||c%2>0||!(a,b,c=b/2+c/2,c/2+a/2,a/2+b/2;1)}
end
