#!/usr/bin/ruby
gets.to_i.times{
	s=gets.chomp.split('')
	n=s.size
	h={}
	n.times{|i|h[i]=1 if s[i]=='X'}
	r=(1..n).select{|i|n%i==0 && (n/i).times.any?{|j|
		i.times.all?{|k|h[k*(n/i)+j]}
	}}.map{|e|'%dx%d'%[e,n/e]}
	puts r.size.to_s+' '+r*' '
}