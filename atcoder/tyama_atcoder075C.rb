#!/usr/bin/ruby
s=0
q=Float::INFINITY
gets.to_i.times{
	x=gets.to_i
	s+=x
	q=[q,x].min if x%10!=0
}
if s%10!=0
	p s
else
	p [s-q,0].max
end
