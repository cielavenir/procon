#!/usr/bin/ruby
gets.to_i.times{
	n=gets.to_i
	r=(n-1)/2
	a=[1]+[0]*r
	(n+1).times{|i|r.downto(1){|j|a[j]+=i*a[j-1]}}
	p (1..n+1).reduce(:*)/a.reduce(:+)
}
__END__
1
15