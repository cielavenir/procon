#!/usr/bin/ruby
N,Q,*X=`dd`.split.map &:to_i
A=[0]*(N%2)+X.shift(N)
M=-~N/2
L=[]
S=[A[M..-1].reduce(:+)]
M.times{|i|S<<S[-1]+(l=A[2*i+1])-r=A[i+M];L<<(l+r)/2}
X.map{|e|p S[(0...M).bsearch{|i|L[i]>=e}||M]}
