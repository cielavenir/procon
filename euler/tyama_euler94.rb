#!/usr/bin/ruby
require 'backports' if RUBY_VERSION<'2.0'
gets
N=$<.map(&:to_i)
M=N.max
a,b=2,1;
A=(0..1/0.0).lazy.map{a,b=a*2+b*3,a+b*2;s=2*(a%3==1?a+1:a-1)}.take_while{|s|s<=M}.to_a
N.each{|e|
	idx=(0...A.size).bsearch{|i|A[i]>e}||A.size
	p A[0,idx].reduce(:+)
}
	
__END__
1
1000000000