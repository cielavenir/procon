#!/usr/bin/ruby
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
gets.to_i.times{
	M,X=gets.split.map(&:to_i)
	a=[1]*M+[2]
	s=0
	p M+1+(M+1..1/0.0).lazy.take_while{|i|s+=a[i-M-1];(a<<1+s+a[i-1]).last<=X}.count
}
__END__
1
50 1000000