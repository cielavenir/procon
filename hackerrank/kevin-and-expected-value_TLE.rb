#!/usr/bin/ruby
#y=lambda{|x|10.times.reduce(0){|s,_|Math.sqrt(x+s)}}
y=lambda{|x|x==0 ? 0 : (1+Math.sqrt(1+4*x))/2}
n=5000000
a=[0]+(1...n).map(&y)
(1...n).each{|i|a[i]+=a[i-1]}
gets.to_i.times{
	m=gets.to_i
	if m<=n
		p a[m-1]/m
	else
=begin
		l=1000
		s=0
		l.times{
			s+=y[rand(0...m)]
		}
		p s/l
=end
		p -1
	end
}