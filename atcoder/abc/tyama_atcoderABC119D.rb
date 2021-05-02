#!/usr/bin/ruby
A,B,Q=gets.split.map &:to_i
I=1<<60
S=[-I]+A.times.map{gets.to_i}+[I]
T=[-I]+B.times.map{gets.to_i}+[I]
Q.times{
	x=gets.to_i
	b=S.bsearch_index{|e|x<e}||S.size
	d=T.bsearch_index{|e|x<e}||T.size
	r=I
	[S[b-1],S[b]].each{|s|[T[d-1],T[d]].each{|t|
		r=[r,(t-s).abs+(s-x).abs,(s-t).abs+(t-x).abs].min
	}}
	p r
}
