#!/usr/bin/ruby
puts gets.to_i.times.map{
	s=gets.chomp
	endidx=s.rindex(/\d/)
	next s if !endidx
	endidx+=1
	beginidx=(s[0,endidx].rindex(/[^\d]/)||-1)+1
	q=s[beginidx...endidx]
	if q[0]==?0
		q='%0*d'%[q.size,q.to_i+1]
	else
		q=(q.to_i+1).to_s
	end
	s[0,beginidx]+q+s[endidx..-1]
}
