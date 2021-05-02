#!/usr/bin/ruby
N=gets.to_i
A=gets.split.map(&:to_i)
S=gets.chomp
#p A.sort[N/2]
if S.chars.all?{|e|e=='M'}
	p A.max
elsif S.chars.all?{|e|e=='m'}
	p A.min
else
	z=S.index('m')
	p A.each_cons(z).map(&:max).min
	#p A.sort[S.index('m')]
end
