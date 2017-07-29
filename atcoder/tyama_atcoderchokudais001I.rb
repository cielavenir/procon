#!/usr/bin/ruby
eval'N,*A='+`dd`.split*?,;p (0...N).count{|i|k=A[i];k+=A[i]while k<N&&N>i+=1;k==N}
