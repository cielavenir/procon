#!/usr/bin/ruby
M=998244353
N=gets.to_i
v=$<.map{|e|Complex(*e.split.map(&:to_i))}
h={}
r=2**N+~N
[*0...N].combination(2){|i,j|
	h[x=[i,j]]||(
	x+=(j+1...N).select{|k|((v[j]-v[k]).conj*(v[i]-v[k])).imag==0};
	r-=2**(l=x.size)+~l;
	x.combination(2){|e|h[e]=1})
}
p r
