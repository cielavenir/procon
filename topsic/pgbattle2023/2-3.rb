#!/usr/bin/ruby
N,K,*a=`dd`.split.map &:to_i
M=998244353;I=[1,1];*F=I;*R=I
2.upto(N){|i|I<<z=(M-M/i)*I[M%i]%M;F<<i*F[-1]%M;R<<z*R[-1]%M}
p K>0?a.group_by.with_index{|e,i|i%K}.each_value.reduce(1){|s,v|v.group_by(&:to_i).each_value.reduce(s*F[v.size]){|s,_|s*R[_.size]}%M}:1
