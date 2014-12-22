#!/usr/bin/ruby
#codeforces379A
gets.to_i.times{
n,c,b=gets.split.map(&:to_i)
a=n/c
r=0
x=0
while a>0
	r+=a
	x+=a
	a=x/b
	x%=b
end
p r
}