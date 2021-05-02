#!/usr/bin/ruby
def convert(a)
	s=0
	a.map!{|e|
		s+=e
		s
	}
end
N,M=gets.split.map(&:to_i)
A=N.times.map{gets.split.map(&:to_i)}
r=0
1.upto(N-1){|i|
	while (A[i-1]<=>A[i])>=0 #!compare(A[i-1],A[i])
		convert(A[i])
		r+=1
		raise if r>10000
	end
}
p r
