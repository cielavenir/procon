#!/usr/bin/ruby
require 'rational'
while(n=gets.to_i)>0
	a=n.times.map{gets.split.map(&:to_i)}
	l=1;n.times{|i|l*=a[i][0]/l.gcd(a[i][0])}
	b=n.times.map{|i|a[i][1]*l/a[i][0]}
	g=b[0];n.times{|i|g=g.gcd b[i]}
	n.times{|i|p b[i]/g}
end