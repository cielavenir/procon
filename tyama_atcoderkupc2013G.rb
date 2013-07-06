#!/usr/bin/ruby
N=40
K=5
p N
puts N.times.map{|i|
	i<K ? 'Y'*i+'N'+'Y'*(N-i-1) : 'Y'*K+'N'*(N-K)
}