#!/usr/bin/ruby
P=->n{n<1?0:P[n/2]+n%2}
N,K,*a=`dd`.split.map &:to_i
p ([0,*a.sort,2**N-r=1]).each_cons(2).all?{|x,y|r*=(1..P[x^y]).reduce 1,:*;x&y==x}?r%(10**9+7):0
