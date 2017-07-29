#!/usr/bin/ruby
#https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q1063451530
eval'N,*A='+`dd`.split*?,;M=10**9+7;a=[];q=[r=1]
N.times{|i|q<<q[-1]*-~i%M}
N.times{|i|
	a.insert(k=a.bsearch_index{|e|e<A[i]}||i,A[i])
	r=(r+(A[i]+~i+k)*q[N+~i])%M
}
p r
