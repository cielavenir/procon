#!/usr/bin/ruby
N=gets.to_i
A=gets.split.map(&:to_i)
D=[*0..10**6]
s=0
2.upto(N-2){|i|
	s+=A[i]
	1.upto(A[i]){|j|D.unshift D[j*2-1]}
}
gets;$<.map{|e|
	p (D[x=e.to_i]||x-s)+A[0]-A[1]
}
__END__
gets.to_i.times{
	x=gets.to_i
	(N-2).downto(2){|i|x=(x-A[i]).abs}
	p x+A[0]-A[1]
}
