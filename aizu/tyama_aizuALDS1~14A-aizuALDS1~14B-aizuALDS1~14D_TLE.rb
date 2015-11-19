#!/usr/bin/ruby
s=gets.chomp+'$'
n=s.size
suff=n.times.sort_by{|i|s[i..-1]}
bwt=suff.map{|e|s[(e-1)%n]}
sorted=n.times.map{|i|[bwt[i],i]}.sort
gets.to_i.times{
	q=gets.chomp.reverse
	start=0
	stop=n
	if q.size.times{|i|
		start,stop=[
			(0...n).bsearch{|j|(sorted[j]<=>[q[i],start]) >= 0}||n,
			(0...n).bsearch{|j|(sorted[j]<=>[q[i],stop]) >= 0}||n,
		]
		break if start==stop
	} then
		#puts (start...stop).map{|i|suff[i]}.sort
		p 1
	else
		p 0
	end
}