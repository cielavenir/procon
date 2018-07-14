#!/usr/bin/ruby
class Ternary
	def initialize(n)
		@n=n
	end
	def to_i
		@n
	end
	def -@
		Ternary.new(2-to_i)
	end
	def *(o)
		Ternary.new([to_i,o.to_i].min)
	end
	def +(o)
		Ternary.new([to_i,o.to_i].max)
	end
end
R=[*0..2]
loop{
	s=gets.chomp
	break if s=='.'
	r=0
	R.repeated_permutation(3){|a,b,c|
		r+=1 if eval([['0',0],['1',1],['2',2],['P',a],['Q',b],['R',c]].reduce(s){|x,(y,z)|x.gsub(y,'Ternary.new(%d)'%z)}).to_i==2
	}
	p r
}
