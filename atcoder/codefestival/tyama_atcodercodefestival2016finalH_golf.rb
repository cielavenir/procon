#!/usr/bin/ruby
N,*M=`dd`.split.map &:to_i;X,Y,*A,_=M.shift N;D=*0..1e6;s=0;A.map{|e|s+=e.times{|j|D.unshift D[j*2+1]}};M.map{|e|p (D[e]||e-s)+X-Y}
