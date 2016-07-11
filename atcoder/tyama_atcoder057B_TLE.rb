#!/usr/bin/ruby
N,K=gets.split.map(&:to_i)
A=$<.map(&:to_i)
S=[0]
(1..N).each{|i|S[i]=S[i-1]+A[i-1]}
(p 1;exit)if S[N]==K
D=[0,1,*[1<<29]*(N-1)]
(1...N).each{|n|
	(n+1).downto(1){|i|
		if D[i-1]<S[n]
			D[i]=[D[i],D[i-1]+A[n]*D[i-1]/S[n]+1].min
		end
	}
}
p N.downto(0).find{|i|p(D[i])<=K}