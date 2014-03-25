#!/usr/bin/ruby
a=[]
0.step(999,8){|i|
	s='%03d'%i
	h=Hash.new(0)
	s.chars{|c|h[c]+=1}
	a<<h
}
gets.to_i.times{
	s=gets.chomp
	if s.size<4
		puts s.split('').permutation.any?{|b|b.join.to_i%8==0} ? 'YES' : 'NO'
	else
		h=Hash.new(0)
		s.chars{|c|h[c]+=1}
		puts a.any?{|e|
			e.all?{|k,v|h[k]>=v}
		} ? 'YES' : 'NO'
	end
}