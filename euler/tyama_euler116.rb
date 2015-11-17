#!/usr/bin/ruby
gets.to_i.times{
	z=gets.to_i
	p [2,3,4].map{|n|
		a=[1]*n
		n.step(z){|i|a<<a[i-n]+a[i-1]}
		a.last-1
	}.reduce(:+)%1000000007
}
__END__
1
50