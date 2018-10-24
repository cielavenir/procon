#!/usr/bin/ruby
gets.to_i.times{
a,b,c=gets.split.map &:to_i
if c%2>0
	puts :No;next
end
s=100*a+10*b+c>>1
s-=[100*a,s].min/100*100
s-=[10*b,s].min/10*10
s-=[c,s].min
puts s>0 ? :No : :Yes
}
