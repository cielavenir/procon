#!/usr/bin/ruby
gets.to_i.times{
	z=gets.to_i
	a=[1]
	1.step(z){|i|a<<a[[0,i-4].max..i].reduce(:+)}
	p a.last%1000000007
}
__END__
1
50