#!/usr/bin/ruby
def simulate(s)
(-2..2).map{|i|
	n=i
	s.reverse.each_char{|c|
		n=-n if c=='-'
		n=n==0 ? 1 : 0 if c=='!'
	}
	n
}
end

INF='!!!!'
s=gets.chomp
z=simulate(s)
r=INF
(0..3).each{|i|
	['-','!'].repeated_permutation(i){|a|
		s=a.join
		r=s if r.size>s.size&&simulate(s)==z
	}
}
raise if r==INF
puts r