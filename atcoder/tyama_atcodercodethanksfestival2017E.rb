#!/usr/bin/ruby
n=gets.to_i;s=['!']
((n+4)/5).times{|i|
	a=[0]*n
	(k=[5,n-i*5].min).downto(1){|j|a[i*5+k-j]=5**~-j}
	puts '? '+a*' '
	STDOUT.flush
	s+=(gets.to_i-2*5**k+2).to_s(5).rjust(k,'0').tr('234','010').chars
}
puts s*' '
