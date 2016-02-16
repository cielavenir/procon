#!/usr/bin/ruby
require 'prime'
gets.to_i.times{
	b=gets.to_i
	n=0
	Prime.each{|e|
		n+=1
		if n%2==0 then next end
		if 2*n*e>b then break end
	}
	p n
}
__END__
1
10000000000