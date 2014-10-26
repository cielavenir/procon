#!/usr/bin/ruby
require 'prime'
N,K,L=gets.split.map(&:to_i)
(10**(N-1)...10**N).each{|i|
	p i
	s=i.to_s.chars.to_a
	[*0...N].combination(K){|a| #a==digit to replace
		s0=s.dup
		l=0
		('0'..'9').each.with_index(1){|j,_|
			a.each{|e|s0[e]=j}
			l+=1 if s0[0]!='0' && s0.join.to_i.prime?
			break if 10-(_-l)<L
		}
		#output
		if l>=L
			result=[]
			('0'..'9').each{|j|
				a.each{|e|s0[e]=j}
				next if s0[0]=='0'
				x=s0.join.to_i
				result<<x if x.prime?
				break if result.size==L
			}
			puts result*' '
			exit
		end
	}
}
__END__
6 3 8