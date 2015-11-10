#!/usr/bin/ruby
N,M=gets.split.map(&:to_i)
if N<M
	p 1
	exit
end
a=[1]*M+[2]
s=0
(M+1).step(N){|i|s+=a[i-M-1];a<<(1+s+a[i-1]) %1000000007}
p a.last
__END__
50 3